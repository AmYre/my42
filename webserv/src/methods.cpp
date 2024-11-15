/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 02:52:50 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/11 19:46:23 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

void handle_GET(request &req)
{
	if (strcmp(req.path.c_str(), "/") == 0)
		req.path = "/static/home/index.html";
	if (strcmp(req.path.c_str(), "/static/test-cgi") == 0)
		call_GET_CGI(req);
	if (strcmp(req.path.c_str(), "/static/del/del.html") == 0)
		call_DEL_CGI();
	check_rooting(req);
	if (check_redirects(req))
		return;
	if (is_directory(req.path))
		return (check_directories(req));
	req.response = "GRANTED";
}

void handle_POST(int client_fd, request &req)
{
	if (strcmp(req.path.c_str(), "/upload") == 0)
	{
		if (req.ongoing)
			compose_file(req);
		else
			upload_file(req);
	}
	else
	{
		if (req.current_conf && req.body.size() > static_cast<size_t>(req.current_conf->max_body_size))
		{
			req.response = "LIMIT";
			return;
		}
		call_POST_CGI(req.body, client_fd);
	}
}

void handle_DEL(request &req)
{
	std::string file_path = "." + std::string(req.path);
	if (file_path.find("/public/") == std::string::npos)
	{
		req.response = "DENIED";
		return;
	}
	if (std::remove(file_path.c_str()) == 0)
		req.response = "DELETED";
	else
		req.response = "ERROR";
}
