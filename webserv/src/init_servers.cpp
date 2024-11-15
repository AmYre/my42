/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_servers.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:20:44 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/11 19:12:46 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

std::vector<int> create_server_sockets(std::vector<serverConf> &server_configs)
{
	struct in_addr addr;

	std::vector<int> server_sockets;
	for (std::vector<serverConf>::const_iterator it = server_configs.begin(); it != server_configs.end(); ++it)
	{

		int server_socket = socket(AF_INET, SOCK_STREAM, 0);
		if (server_socket == -1)
		{
			std::cerr << "Failed to create socket: " << strerror(errno) << std::endl;
			exit(1);
		}

		int opt = 1;
		if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
		{
			std::cerr << "Failed to set SO_REUSEADDR to make the server reboots rapidly: " << strerror(errno) << std::endl;
			close(server_socket);
			exit(1);
		}

		if (fcntl(server_socket, F_SETFL, O_NONBLOCK) == -1)
		{
			std::cerr << "Failed to set non-blocking mode: " << strerror(errno) << std::endl;
			close(server_socket);
			exit(1);
		}
		struct sockaddr_in server_address;
		server_address.sin_family = AF_INET;
		server_address.sin_port = htons(it->port);
		if (it->hostname == "localhost")
			server_address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
		else if (inet_pton(AF_INET, it->hostname.c_str(), &addr) == 1)
			server_address.sin_addr.s_addr = addr.s_addr;
		else
			server_address.sin_addr.s_addr = INADDR_ANY;

		if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1)
		{
			std::cerr << "Failed to bind socket: " << strerror(errno) << std::endl;
			close(server_socket);
			continue;
		}

		if (listen(server_socket, 10) == -1)
		{
			std::cerr << "Failed to listen on socket: " << strerror(errno) << std::endl;
			close(server_socket);
			exit(1);
		}

		std::cout << "Server socket created: " << server_socket << " on port " << it->port << std::endl;
		server_sockets.push_back(server_socket);
	}
	return server_sockets;
}

int epoll_init(const std::vector<int> &server_sockets, struct epoll_event &event)
{
	int epoll_fd = epoll_create(1);
	if (epoll_fd == -1)
	{
		std::cerr << "Failed to create epoll file descriptor: " << strerror(errno) << std::endl;
		return 1;
	}
	else
		fcntl(epoll_fd, F_SETFL, FD_CLOEXEC);

	for (std::vector<int>::const_iterator it = server_sockets.begin(); it != server_sockets.end(); ++it)
	{
		event.events = EPOLLIN;
		event.data.fd = *it;

		if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, *it, &event) == -1)
		{
			std::cerr << "Failed to add server socket to epoll: " << strerror(errno) << std::endl;
			close(*it);
			close(epoll_fd);
			return 1;
		}
	}

	return epoll_fd;
}
