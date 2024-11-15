/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:21:59 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/11 19:45:41 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

void handleIn_request(int client_fd, request &req, std::vector<serverConf> &server_configs)
{
	std::string content = read_socket(client_fd);
	parse_request(content, req);
	// my_prints(content, req);
	find_server_conf(server_configs, req);
	if (!allowed_path(req.path))
	{
		req.response = "DENIED";
		return;
	}

	if (strcmp(req.method.c_str(), "GET") == 0)
	{
		if (req.current_conf->allowed_methods[req.path].empty())
			handle_GET(req);
		else
		{
			if (req.current_conf->allowed_methods[req.path].find("GET") != std::string::npos)
				handle_GET(req);
			else
				req.response = "NOT ALLOWED";
		}
	}
	else if (strcmp(req.method.c_str(), "POST") == 0)
	{
		if (req.current_conf->allowed_methods[req.path].empty())
			handle_POST(client_fd, req);
		else
		{
			if (req.current_conf->allowed_methods[req.path].find("POST") != std::string::npos)
				handle_POST(client_fd, req);
			else
				req.response = "NOT ALLOWED";
		}
	}
	else if (strcmp(req.method.c_str(), "DELETE") == 0)
	{
		if (req.current_conf->allowed_methods[req.path].empty())
			handle_DEL(req);
		else
		{
			if (req.current_conf->allowed_methods[req.path].find("DELETE") != std::string::npos)
				handle_DEL(req);
			else
				req.response = "NOT ALLOWED";
		}
	}
	else
		req.response = "NOT IMPLEMENTED";
}

void handleOut_response(int client_fd, request &req)
{
	if (req.response == "GRANTED")
		handle_granted(client_fd, req);
	else if (!req.response.empty())
	{
		if (req.response == "DENIED")
		{
			if (req.current_conf && !req.current_conf->error_page.empty())
				write_response400(client_fd, 403, req.current_conf->error_page);
			else
				write_response400(client_fd, 403, "./static/error/403.html");
		}
		else if (req.response == "DELETED")
		{
			const char *response = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n";
			int result = write(client_fd, response, strlen(response));
			if (result <= 0)
				close(client_fd);
		}
		else if (req.response == "ERROR")
		{
			if (req.current_conf && !req.current_conf->error_page.empty())
				write_response500(client_fd, 500, req.current_conf->error_page);
			else
				write_response500(client_fd, 500, "./static/error/500.html");
		}
		else if (req.response == "UPLOADED")
			write_response200(client_fd, 200, req, "File uploaded successfully");
		else if (req.response == "LIMIT")
			write_response400(client_fd, 413, "./static/error/413.html");
		else if (req.response == "REDIRECT")
			write_response300(client_fd, req.path);
		else if (req.response == "AUTOINDEX")
			handle_autoindex(client_fd);
		else if (req.response == "DEFAULT PAGE")
			write_response400(client_fd, 403, req.current_conf->default_page);
		else if (req.response == "NOT ALLOWED")
			write_response400(client_fd, 405, "./static/error/405.html");
		else if (req.response == "NOT IMPLEMENTED")
			write_response500(client_fd, 501, "./static/error/501.html");
		req = request();
	}
}
