/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 23:27:13 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/10 21:06:34 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

volatile sig_atomic_t stop;

int main(int argc, char **argv)
{
	std::string config_file = "./webserv.conf";
	if (argc != 2)
	{
		std::cerr << "Needs one argument, no more, no less" << std::endl;
		std::cerr << "Usage: ./webserv [./path/config_file]" << std::endl;
		std::cerr << "Used default config file : ./webserv.conf" << std::endl;
	}
	else
		config_file = argv[1];

	std::vector<serverConf> server_configs = parse_config(config_file);
	std::vector<int> server_sockets = create_server_sockets(server_configs);

	request req;
	serverConf current_conf;

	struct epoll_event event;
	std::vector<int> client_sockets;
	struct epoll_event events[MAX_EVENTS];
	int epoll_fd = epoll_init(server_sockets, event);

	signal(SIGINT, handle_signal);

	while (!stop)
	{
		int waiting_fds = epoll_wait(epoll_fd, events, MAX_EVENTS, 5000);
		if (waiting_fds == -1)
		{
			if (errno == EINTR)
				continue;
			std::cerr << "Failed to wait on epoll: " << strerror(errno) << std::endl;
			break;
		}

		for (int i = 0; i < waiting_fds; ++i)
		{
			if (std::find(server_sockets.begin(), server_sockets.end(), events[i].data.fd) != server_sockets.end())
			{
				while (true)
				{
					struct sockaddr_in client_address;
					socklen_t client_addrlen = sizeof(client_address);
					int client_socket = accept(events[i].data.fd, (struct sockaddr *)&client_address, &client_addrlen);
					if (client_socket == -1)
					{
						if (errno == EAGAIN || errno == EWOULDBLOCK)
							break;
						else
						{
							std::cerr << "Failed to accept connection: " << strerror(errno) << std::endl;
							break;
						}
					}
					client_sockets.push_back(client_socket);
					if (fcntl(client_socket, F_SETFL, O_NONBLOCK) == -1)
					{
						std::cerr << "Failed to set non-blocking mode: " << strerror(errno) << std::endl;
						close(client_socket);
						continue;
					}

					event.events = EPOLLOUT | EPOLLIN;
					event.data.fd = client_socket;
					if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_socket, &event) == -1)
					{
						std::cerr << "Failed to add client socket to epoll: " << strerror(errno) << std::endl;
						close(client_socket);
						continue;
					}
				}
			}
			else
			{
				if (events[i].events & EPOLLIN)
				{
					handleIn_request(events[i].data.fd, req, server_configs);
					if (events[i].events & EPOLLOUT)
						handleOut_response(events[i].data.fd, req);
				}
			}
		}
	}

	std::cout << " ==> CTRL-C SIGNAL detected : WebServ shutting down..." << std::endl;
	for (std::vector<int>::iterator client_socket_it = client_sockets.begin(); client_socket_it != client_sockets.end(); ++client_socket_it)
		close(*client_socket_it);
	for (std::vector<int>::iterator server_socket_it = server_sockets.begin(); server_socket_it != server_sockets.end(); ++server_socket_it)
		close(*server_socket_it);
	close(epoll_fd);
	return 0;
}