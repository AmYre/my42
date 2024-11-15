/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 23:23:47 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:23 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"
#include <sys/stat.h>

void parse_request(const std::string &content, request &req)
{
	if (!req.ongoing)
	{
		size_t headers_end = content.find("\r\n\r\n");
		if (headers_end != std::string::npos)
			req.headers = content.substr(0, headers_end + 4);
		if (headers_end != std::string::npos && headers_end + 4 <= content.size())
			req.body = content.substr(headers_end + 4);
		if (!req.body.empty())
			req.filename = read_filename(req.body.c_str());
		std::istringstream stream(req.headers);
		std::string line;
		if (std::getline(stream, line))
		{
			std::istringstream line_stream(line);
			line_stream >> req.method >> req.path;
		}
		read_host(stream, line, req);
		read_length(stream, line, req);
		req.boundary = read_boundary(content.c_str());
		if (!req.boundary.empty())
			check_full_body(content, req);
		else
			req.ongoing = false;
	}
	else
	{
		req.body = content;
		if (req.filename.empty())
			req.filename = read_filename(req.body.c_str());
	}
}

bool check_file(const std::string &path)
{
	struct stat info;
	if (stat(path.c_str(), &info) != 0)
	{
		std::cerr << RED << "Error: Cannot access " << path << RESET << std::endl;
		return false;
	}
	if (S_ISDIR(info.st_mode))
	{
		std::cerr << RED << "Error: " << path << " is a directory" << RESET << std::endl;
		return false;
	}
	if (!(info.st_mode & S_IRUSR))
	{
		std::cerr << RED << "Error: " << path << " does not have read permissions" << RESET << std::endl;
		return false;
	}
	return true;
}

std::vector<serverConf> parse_config(const std::string &config_file)
{
	if (!check_file(config_file))
		exit(1);
	std::vector<serverConf> servers;
	std::ifstream file(config_file.c_str());
	if (file.is_open())
	{
		std::cout << YELLOW << "Opened file: " << config_file << RESET << std::endl;
		std::string line;
		size_t line_count = 0;
		const size_t max_lines = 1000;
		const size_t max_total_size = 1024 * 1024;
		size_t total_size = 0;
		while (std::getline(file, line))
		{
			line_count++;
			total_size += line.size();
			if (line_count > max_lines)
			{
				std::cerr << "Error: Exceeded maximum number of lines (" << max_lines << ")" << std::endl;
				break;
			}
			if (total_size > max_total_size)
			{
				std::cerr << "Error: Exceeded maximum total size of data (" << max_total_size << " bytes)" << std::endl;
				break;
			}
			if (line.find("server") != std::string::npos)
			{
				if (line.find("#") != std::string::npos)
					continue;
				serverConf server;
				std::string next_line;
				int brace_depth = 1;
				std::string location = "";
				std::string root = "";
				std::string redirect = "";
				std::string methods = "";
				while (std::getline(file, next_line) && brace_depth > 0)
				{
					if (next_line.find("#") != std::string::npos)
						continue;
					if (next_line.find("{") != std::string::npos)
						brace_depth++;
					if (next_line.find("}") != std::string::npos)
						brace_depth--;
					parse_port(next_line, server);
					parse_hostname(next_line, server);
					parse_max_file_size(next_line, server);
					parse_max_body_size(next_line, server);
					parse_error_page(next_line, server);
					parse_autoindex(next_line, server);
					parse_default_page(next_line, server);
					if (location.empty())
						location = parse_location(next_line);
					if (root.empty())
						root = parse_route_root(next_line);
					if (redirect.empty())
						redirect = parse_redirection(next_line);
					if (methods.empty())
						methods = parse_allowed_methods(next_line);
					if (!redirect.empty() && !location.empty())
					{
						server.redirects[location] = redirect;
						redirect = "";
					}
					if (!root.empty() && !location.empty())
					{
						server.routes[location] = root;
						root = "";
					}
					if (!methods.empty() && !location.empty())
					{
						server.allowed_methods[location] = methods;
						methods = "";
					}
					if (brace_depth == 1)
						location = "";
				}
				if (file.bad())
					std::cerr << "Error: An error occurred while reading the file." << std::endl;
				server_checks(server, file);
				servers.push_back(server);
			}
		}
	}
	else
	{
		std::cerr << RED << "Failed to open config file: " << strerror(errno) << RESET << std::endl;
		file.close();
		exit(1);
	}
	if (servers.empty())
	{
		std::cerr << RED << "No server found in config file" << RESET << std::endl;
		file.close();
		exit(1);
	}
	std::cout << YELLOW << "----------------- current servers vector size: " << servers.size() << RESET << std::endl;
	print_servers_info(servers);
	file.close();
	return (servers);
}
