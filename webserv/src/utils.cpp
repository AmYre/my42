/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:49:04 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/11 19:10:56 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

std::string get_mime_type(const std::string &path)
{
	std::map<std::string, std::string> mime_types;
	mime_types[".html"] = "text/html";
	mime_types[".css"] = "text/css";
	mime_types[".js"] = "application/javascript";
	mime_types[".png"] = "image/png";
	mime_types[".jpg"] = "image/jpeg";
	mime_types[".ico"] = "image/x-icon";
	mime_types[".json"] = "application/json";
	mime_types[".pdf"] = "application/pdf";
	mime_types[".mp4"] = "video/mp4";
	mime_types[".txt"] = "text/plain";

	size_t dot_pos = path.find_last_of('.');
	if (dot_pos != std::string::npos)
	{
		std::string ext = path.substr(dot_pos);
		if (mime_types.find(ext) != mime_types.end())
		{
			return mime_types[ext];
		}
	}
	return "application/octet-stream";
}

std::string get_status(int status)
{
	std::map<int, std::string> status_codes;
	status_codes[200] = "OK";
	status_codes[201] = "Created";
	status_codes[202] = "Accepted";
	status_codes[204] = "No Content";
	status_codes[300] = "Multiple Choices";
	status_codes[301] = "Moved Permanently";
	status_codes[302] = "Found";
	status_codes[303] = "See Other";
	status_codes[304] = "Not Modified";
	status_codes[305] = "Use Proxy";
	status_codes[307] = "Temporary Redirect";
	status_codes[308] = "Permanent Redirect";
	status_codes[400] = "Bad Request";
	status_codes[401] = "Unauthorized";
	status_codes[403] = "Forbidden";
	status_codes[404] = "Not Found";
	status_codes[405] = "Method Not Allowed";
	status_codes[408] = "Request Timeout";
	status_codes[411] = "Length Required";
	status_codes[413] = "Payload Too Large";
	status_codes[500] = "Internal Server Error";
	status_codes[501] = "Not Implemented";
	status_codes[502] = "Bad Gateway";
	status_codes[505] = "HTTP Version Not Supported";

	if (status_codes.find(status) != status_codes.end())
		return status_codes[status];
	return "Internal Server Error";
}

std::string read_socket(int client_fd)
{
	const size_t buffer_size = 65536;
	std::vector<char> buffer(buffer_size);
	ssize_t bytes_read;

	bytes_read = read(client_fd, buffer.data(), buffer_size);
	if (bytes_read <= 0)
	{
		close(client_fd);
		return "";
	}

	return std::string(buffer.data(), bytes_read);
}

std::string read_file(const std::string &path)
{
	std::ifstream file(path.c_str(), std::ios::binary);
	if (!file)
		return "";
	std::ostringstream ss;
	ss << file.rdbuf();
	return ss.str();
}

void upload_file(request &req)
{
	if (req.current_conf && req.file.size() > static_cast<size_t>(req.current_conf->max_file_size * 1024 * 1024))
	{
		req.response = "LIMIT";
		return;
	}
	std::string filepath = "public/" + req.filename;
	std::ofstream outfile(filepath.c_str(), std::ios::binary);
	if (!outfile)
	{
		req.response = "ERROR";
		return;
	}
	outfile.write(req.file.c_str(), req.file.size());
	if (outfile.fail())
		req.response = "ERROR";
	else
		req.response = "UPLOADED";
	outfile.close();
}

std::string read_filename(const char *buffer)
{
	const char *start = strstr(buffer, "Content-Disposition: form-data;");
	if (start == NULL)
		return "";

	const char *filename_start = strstr(start, "filename=\"");
	if (filename_start == NULL)
		return "";

	filename_start += 10;
	const char *filename_end = strstr(filename_start, "\"");
	if (filename_end == NULL)
		return "";

	return std::string(filename_start, filename_end - filename_start);
}

std::string read_boundary(const char *buffer)
{
	const char *start = strstr(buffer, "boundary=");
	if (start == NULL)
		return "";

	start += 9;
	const char *end = strstr(start, "\r\n");
	if (end == NULL)
		return "";

	return std::string(start, end - start);
}

void write_response200(int client_fd, int status, request &req, const std::string &content)
{
	std::string type = get_mime_type(req.path);
	std::ostringstream response;
	response << "HTTP/1.1 " << status << " OK\r\n";
	response << "Content-Length: " << content.size() << "\r\n";
	response << "Content-Type: " << type << "\r\n";
	generate_session_id(req);
	if (!req.is_id)
	{
		response << "Set-Cookie: session_id=" << req.id << "\r\n";
		req.is_id = true;
	}
	response << "\r\n";
	response << content;
	int result = write(client_fd, response.str().c_str(), response.str().size());
	if (result <= 0)
		close(client_fd);
}

void write_response300(int client_fd, std::string redirect_infos)
{
	std::cout << "Redirecting to: " << redirect_infos << std::endl;
	std::istringstream redirect(redirect_infos);
	std::string status, url;
	redirect >> status >> url;
	std::string type = get_status(atoi(status.c_str()));
	std::cout << "Redirecting to: " << url << std::endl;
	std::cout << "Status: " << status << std::endl;
	std::cout << "Type: " << type << std::endl;

	std::string body = "<html><head><title>Redirect</title></head><body>Redirected to another address</body></html>";

	std::ostringstream response;
	response << "HTTP/1.1 " << status << type << "\r\n";
	response << "Location: " << url << "\r\n";
	response << "Content-Type: text/html\r\n";
	response << "Content-Length: " << body.length() << "\r\n";
	response << "Connection: close\r\n";
	response << "\r\n";
	response << body;

	int result = write(client_fd, response.str().c_str(), response.str().size());
	if (result <= 0)
		std::cerr << "Failed to write response: " << strerror(errno) << std::endl;
	close(client_fd);
}

void write_response400(int client_fd, int status, const std::string &err_file)
{
	std::ostringstream response;
	std::string path_file;
	if (err_file[0] != '.')
	{
		path_file = err_file;
		path_file.insert(0, 1, '.');
	}
	else
		path_file = err_file;
	std::string file = read_file(path_file);
	if (file.empty())
		file = read_file("./static/error/error.html");
	std::string type = get_status(status);
	response << "HTTP/1.1 " << status << type << "\r\n";
	response << "Content-Type: text/html\r\n";
	response << "Content-Length: " << file.size() << "\r\n";
	response << "\r\n";
	response << file;
	int result = write(client_fd, response.str().c_str(), response.str().size());
	if (result <= 0)
		close(client_fd);
}

void write_response500(int client_fd, int status, const std::string &err_file)
{
	std::string content = read_file(err_file);
	if (content.empty())
		content = read_file("./static/error/error.html");
	std::ostringstream response;
	std::string type = get_status(status);
	response << "HTTP/1.1 " << status << type << "\r\n";
	response << "Content-Length: " << content.size() << "\r\n";
	response << "Content-Type: text/html\r\n";
	response << "\r\n";
	response << content;
	int result = write(client_fd, response.str().c_str(), response.str().size());
	if (result <= 0)
		close(client_fd);
}

void my_prints(std::string content, request &req)
{
	std::cout << GREEN << "💫|=============full==========|💫" << std::endl;
	std::cout << content << std::endl;
	std::cout << RESET << std::endl;

	std::cout << YELLOW << "🙉|============headers==========|🙉" << std::endl;
	std::cout << req.headers << std::endl;
	std::cout << RESET << std::endl;

	std::cout << BLUE << "🏋️‍♂️|=============body==========|🏋️‍♂️" << std::endl;
	debug_content(req.body);
	std::cout << RESET << std::endl;

	std::cout << MAGENTA << "🚃|=============bounds==========|🚃" << std::endl;
	std::cout << req.boundary << std::endl;
	std::cout << RESET << std::endl;

	std::cout << CYAN << "🎫|=============file==========|🎫" << std::endl;
	debug_content(req.file);
	std::cout << RESET << std::endl;

	std::cout << RED << "🌱|=============name==========|🌱" << std::endl;
	std::cout << req.filename << std::endl;
	std::cout << RESET << std::endl;

	std::cout << BOLD << "⏳|=============path==========|⏳" << std::endl;
	std::cout << req.path << std::endl;
	std::cout << RESET << std::endl;

	std::cout << BOLD << "⏳|=============session ID==========|⏳" << std::endl;
	std::cout << "ID = " << req.id << std::endl;
	std::cout << RESET << std::endl;
}

void debug_content(const std::string &content)
{
	std::vector<std::string> lines;
	std::istringstream stream(content);
	std::string line;

	while (std::getline(stream, line))
		lines.push_back(line);

	if (lines.size() >= 2)
	{
		std::cout << lines[0] << std::endl;
		std::cout << lines[1] << std::endl;
	}
	std::cout << "[...]" << std::endl;
	if (lines.size() >= 4)
	{
		std::cout << lines[lines.size() - 2] << std::endl;
		std::cout << lines[lines.size() - 1] << std::endl;
	}
}

void compose_file(request &req)
{
	size_t first_line_end = req.body.find("\r\n");
	std::string first_line = req.body.substr(0, first_line_end);
	size_t boundary_start = first_line.find("--" + req.boundary);
	size_t boundary_end = req.body.find("--" + req.boundary + "--");

	if (boundary_start == std::string::npos && boundary_end == std::string::npos)
		req.file.append(req.body);
	else if (boundary_start == std::string::npos && boundary_end != std::string::npos)
	{
		// Only End Boundary found
		size_t boundary_length = ("--" + req.boundary + "--").length();
		req.file.append(req.body.substr(0, boundary_end - boundary_length));
		upload_file(req);
	}
	else if (boundary_start != std::string::npos && boundary_end == std::string::npos)
	{
		// Only Start Boundary found
		size_t pos = req.body.find("\r\n\r\n");
		req.file = req.body.substr(pos + 4);
	}
	else if (boundary_start != std::string::npos && boundary_end != std::string::npos)
	{
		// Both boundaries are found
		std::string file_content = req.body.substr(boundary_start + req.boundary.length() + 4, boundary_end - boundary_start - req.boundary.length() - 4);
		size_t pos = file_content.find("\r\n\r\n");
		if (pos != std::string::npos)
		{
			req.file = file_content.substr(pos + 4);
			upload_file(req);
		}
	}
}

void generate_session_id(request &req)
{
	size_t pos = req.headers.find("session_id");
	if (pos != std::string::npos)
	{
		size_t start = req.headers.find("=", pos) + 1;
		size_t end = req.headers.find("\r\n", start);
		req.id = req.headers.substr(start, end - start);
		req.is_id = true;
	}
	else
	{
		std::srand(std::time(0));
		std::stringstream ss;
		ss << std::rand();

		req.id = ss.str();
		req.is_id = false;
	}
}

void check_full_body(const std::string &content, request &req)
{
	size_t body_start = content.find("\r\n\r\n") + 4;
	size_t boundary_start = content.find("--" + req.boundary, body_start);
	size_t boundary_end = content.find("--" + req.boundary + "--", boundary_start);

	if (boundary_start != std::string::npos && boundary_end != std::string::npos && boundary_end > boundary_start)
	{
		std::string file_content = content.substr(boundary_start + req.boundary.length() + 4, boundary_end - boundary_start - req.boundary.length() - 4);
		size_t pos = file_content.find("\r\n\r\n");
		if (pos != std::string::npos)
			req.file = file_content.substr(pos + 4);
		else
			req.file = file_content;
		req.ongoing = false;
	}
	else
		req.ongoing = true;
}

void read_host(std::istringstream &stream, std::string &line, request &req)
{
	while (std::getline(stream, line))
	{
		if (line.find("Host:") != std::string::npos)
		{
			std::istringstream line_stream(line);
			std::string header_name;
			line_stream >> header_name >> req.host;
			break;
		}
	}
}

void read_length(std::istringstream &stream, std::string &line, request &req)
{
	while (std::getline(stream, line))
	{
		if (line.find("Content-Length:") != std::string::npos)
		{
			std::istringstream line_stream(line);
			std::string header_name;
			line_stream >> header_name >> req.length;
			break;
		}
	}
}

bool allowed_path(const std::string &path)
{
	if (path == "/" || path == "/upload")
		return true;
	std::vector<std::string> allowed_paths;
	allowed_paths.push_back("/static/");
	allowed_paths.push_back("/public/");
	allowed_paths.push_back("/assets/");

	for (std::vector<std::string>::const_iterator it = allowed_paths.begin(); it != allowed_paths.end(); ++it)
	{
		if (path.find(*it) == 0)
			return true;
	}
	return false;
}

void find_server_conf(std::vector<serverConf> &server_configs, request &req)
{
	for (std::vector<serverConf>::iterator it = server_configs.begin(); it != server_configs.end(); ++it)
	{
		std::istringstream iss(req.host);
		std::string host, port;
		std::getline(iss, host, ':');
		std::getline(iss, port, ':');
		if (it->hostname == host)
		{
			req.current_conf = &(*it);
			break;
		}
		else
			req.current_conf = &server_configs[0];
	}
}

void print_servers_info(const std::vector<serverConf> &servers)
{
	std::cout << GREEN << "--------------PRINTING ALL SERVERS--------------" << std::endl;
	// loop round all serverConf structs in servers vector
	for (std::vector<serverConf>::const_iterator it = servers.begin(); it != servers.end(); ++it)
	{
		std::cout << GREEN << "-------------printing server info in struct-----------" << std::endl;
		if (!it->hostname.empty())
			std::cout << GREEN << "server hostname " << it->hostname << std::endl;
		if (it->port)
			std::cout << GREEN << "server port " << it->port << std::endl;
		if (!it->error_page.empty())
			std::cout << YELLOW << "serve error_page " << it->error_page << std::endl;
		if (!it->error_root.empty())
			std::cout << YELLOW << "server error_root " << it->error_root << std::endl;
		if (it->max_file_size)
			std::cout << GREEN << "server max_file_size " << it->max_file_size << std::endl;
		if (it->max_body_size)
			std::cout << GREEN << "server max_body_size " << it->max_body_size << std::endl;
		if (!it->routes.empty())
		{
			std::cout << MAGENTA << "server routes: " << std::endl;
			for (std::map<std::string, std::string>::const_iterator route = it->routes.begin(); route != it->routes.end(); ++route)
				std::cout << MAGENTA << "location: " << route->first << " root: " << route->second << std::endl;
		}
		if (!it->redirects.empty())
		{
			std::cout << WHITE << "server redirects: " << std::endl;
			for (std::map<std::string, std::string>::const_iterator redirect = it->redirects.begin(); redirect != it->redirects.end(); ++redirect)
				std::cout << WHITE << "location: " << redirect->first << " redirect: " << redirect->second << std::endl;
		}
		if (!it->allowed_methods.empty())
		{
			std::cout << YELLOW << "server allowed_methods: " << std::endl;
			for (std::map<std::string, std::string>::const_iterator method = it->allowed_methods.begin(); method != it->allowed_methods.end(); ++method)
				std::cout << YELLOW << "location: " << method->first << " methods: " << method->second << std::endl;
		}
		if (it->autoindex)
			std::cout << BLUE << "server autoindex is on" << RESET << std::endl;
		else
			std::cout << BLUE << "server autoindex is off" << RESET << std::endl;
		if (!it->default_page.empty())
			std::cout << CYAN << "server default page = " << it->default_page << RESET << std::endl;
		else
			std::cout << CYAN << "server has no default page" << RESET << std::endl;
		std::cout << std::endl;
	}
}

void parse_max_file_size(const std::string &line, serverConf &server)
{
	std::string key, value;
	std::istringstream iss(line);
	if (line.find("max_file_size") != std::string::npos)
	{
		iss >> key >> value;
		server.max_file_size = atoi(value.c_str());
		if (server.max_file_size < 1 || server.max_file_size > 200)
		{
			std::cerr << "Error: max_file_size must be between 1-200MB" << std::endl;
			exit(1);
		}
	}
}

void parse_max_body_size(const std::string &line, serverConf &server)
{
	std::string key, value;
	std::istringstream iss(line);
	if (line.find("max_body_size") != std::string::npos)
	{
		iss >> key >> value;
		server.max_body_size = atoi(value.c_str());
		if (server.max_body_size < 1 || server.max_body_size > 10000)
		{
			std::cerr << "Error: max_body_size must be between 1-10000 Bytes" << std::endl;
			exit(1);
		}
	}
}

void parse_error_page(const std::string &line, serverConf &server)
{
	std::string key, value;
	std::istringstream iss(line);
	if (line.find("error_page") != std::string::npos)
	{
		iss >> key >> value;
		server.error_page = value;
	}
}

void parse_hostname(const std::string &line, serverConf &server)
{
	std::string key, value;
	std::istringstream iss(line);
	if (line.find("hostname") != std::string::npos)
	{
		iss >> key >> value;
		server.hostname = value;
	}
}

void parse_port(const std::string &line, serverConf &server)
{
	if (line.find("listen") != std::string::npos)
	{
		std::stringstream ss(line);
		std::string word, port;
		ss >> word >> port;
		server.port = atoi(port.c_str());
	}
}

std::string parse_location(const std::string &line)
{
	std::string location = "";
	if (line.find("location") != std::string::npos)
	{
		size_t route_len = (line.find("{") - 1) - (line.find("location") + 11);
		location = line.substr(line.find("location") + 11, route_len);
	}
	return (location);
}

std::string parse_route_root(const std::string &line)
{
	std::string root = "";
	if (line.find("root") != std::string::npos)
	{
		size_t root_len = (line.find("\n")) - (line.find("root ") + 5);
		root = line.substr(line.find("root ") + 5, root_len);
	}
	return (root);
}

std::string parse_redirection(const std::string &line)
{
	std::string redirect = "";
	if (line.find("redirect") != std::string::npos)
	{
		size_t redirect_len = (line.find("\n")) - (line.find("redirect ") + 9);
		redirect = line.substr(line.find("redirect ") + 9, redirect_len);
		std::istringstream iss(redirect);
		std::string status, url;

		if (!(iss >> status >> url))
			return "";

		if (status.length() != 3) // Status should be 3 digits
			return "";

		for (size_t i = 0; i < status.length(); ++i)
		{
			if (!isdigit(status[i]))
				return "";
		}

		int status_num = atoi(status.c_str());
		if (status_num < 300 || status_num > 308)
			return "301";

		if (!is_valid_url(url))
			return "";

		redirect = status + " " + url;
	}
	return (redirect);
}

void parse_autoindex(const std::string &line, serverConf &server)
{
	std::string key, value;
	std::istringstream iss(line);
	if (line.find("autoindex") != std::string::npos)
	{
		iss >> key >> value;
		if (value == "on")
			server.autoindex = true;
		else
			server.autoindex = false;
	}
}

void parse_default_page(const std::string &line, serverConf &server)
{
	if (line.find("default_page") != std::string::npos)
	{
		size_t default_page_len = (line.find(";")) - (line.find("default_page ") + 13);
		server.default_page = line.substr(line.find("default_page ") + 13, default_page_len);
	}
}

void server_checks(serverConf &server, std::ifstream &file)
{
	// valid port limits
	if (server.port == 0 || server.port > 65535 || server.port < 1024)
	{
		file.close();
		if (server.port == 0)
			std::cerr << RED << "Error: No port specified" << RESET << std::endl;
		else
			std::cerr << RED << "Error: Port must be between 1024-65535" << RESET << std::endl;
		exit(1);
	}
	// redirects override routes with the same location within server block
	for (std::map<std::string, std::string>::iterator it = server.redirects.begin(); it != server.redirects.end(); ++it)
	{
		if (server.routes.find(it->first) != server.routes.end())
			server.routes.erase(it->first);
	}
}

std::string parse_allowed_methods(const std::string &line)
{
	std::string allowed = "";
	std::string key, value;
	std::istringstream iss(line);
	if (line.find("allowed_methods") != std::string::npos)
	{
		iss >> key;
		size_t allowed_methods_len = (line.find("\n")) - (line.find("allowed_methods ") + 16);
		value = line.substr(line.find("allowed_methods ") + 16, allowed_methods_len);
	}
	return (value);
}

bool is_directory(const std::string &path)
{
	struct stat info;
	std::string rel_path = "." + path;
	if (stat(rel_path.c_str(), &info) != 0)
		return false;
	return (info.st_mode & S_IFDIR) != 0;
}

bool check_redirects(request &req)
{
	if (req.current_conf != NULL && req.current_conf->redirects.find(req.path) != req.current_conf->redirects.end())
	{
		std::istringstream redirect(req.current_conf->redirects[req.path]);
		req.path = redirect.str();
		req.response = "REDIRECT";
		return true;
	}
	else
		return false;
}

void check_directories(request &req)
{
	if (req.current_conf != NULL && req.current_conf->autoindex)
	{
		call_AUTOINDEX_CGI(req);
		req.response = "AUTOINDEX";
	}
	else if (req.current_conf != NULL && !req.current_conf->default_page.empty())
		req.response = "DEFAULT PAGE";
	else
		req.response = "DENIED";
}

void check_rooting(request &req)
{
	if (req.current_conf != NULL && req.current_conf->routes.find(req.path) != req.current_conf->routes.end())
		req.path = req.current_conf->routes[req.path];
}

void handle_granted(int client_fd, request &req)
{
	std::string file_path = "." + std::string(req.path);
	std::string content = read_file(file_path);
	if (!content.empty())
		write_response200(client_fd, 200, req, content);
	else
	{
		if (req.current_conf && !req.current_conf->error_page.empty())
			write_response400(client_fd, 404, req.current_conf->error_page);
		else
			write_response400(client_fd, 404, "./static/error/404.html");
	}
	req = request();
}

void handle_autoindex(int client_fd)
{
	std::string content = read_file("./static/autoindex/autoindex.html");
	std::ostringstream response;
	response << "HTTP/1.1 200 OK\r\n";
	response << "Content-Length: " << content.size() << "\r\n";
	response << "Content-Type: text/html\r\n";
	response << "\r\n";
	response << content;
	int result = write(client_fd, response.str().c_str(), response.str().size());
	if (result <= 0)
		close(client_fd);
}

bool is_valid_url(const std::string &url)
{
	if (url.length() < 4)
		return false;

	// Must start with http:// or https://
	if (url.substr(0, 7) != "http://" && url.substr(0, 8) != "https://")
		return false;

	// Must have something after the protocol
	if (url.find("://") == url.length() - 3)
		return false;

	// Check for invalid characters
	const std::string valid_chars =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-._~:/?#[]@!$&'()*+,;=";
	if (url.find_first_not_of(valid_chars) != std::string::npos)
		return false;

	return true;
}

void handle_signal(int signal)
{
	if (signal == SIGINT)
		stop = 1;
}
