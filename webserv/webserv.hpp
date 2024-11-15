/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 02:39:10 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/10 19:33:37 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <arpa/inet.h>
#include <cerrno>
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <netdb.h>
#include <netinet/in.h>
#include <sstream>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <vector>
#include <unistd.h>
#include <limits.h>

#define MAX_EVENTS 10
extern volatile sig_atomic_t stop;

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"

struct serverConf
{
	int port;
	std::string hostname;
	std::string error_root;
	std::map<std::string, std::string> routes;
	std::map<std::string, std::string> redirects;
	std::map<std::string, std::string> allowed_methods;
	std::string default_page;
	std::string error_page;
	int max_file_size;
	int max_body_size;
	bool autoindex;

	serverConf() : port(0), max_file_size(200), max_body_size(10000), autoindex(false) {};
};

struct request
{
	std::string id;
	std::string method;
	std::string path;
	std::string redirection;
	std::string headers;
	std::string body;
	std::string boundary;
	std::string file;
	std::string filename;
	std::string response;
	std::string host;
	size_t length;
	bool ongoing;
	bool is_id;
	serverConf *current_conf;

	request() : length(0), ongoing(false), is_id(false), current_conf(NULL) {};
};

// EPOLL MAIN LOOP
std::vector<int> create_server_sockets(std::vector<serverConf> &server_configs);
int epoll_init(const std::vector<int> &server_sockets, struct epoll_event &event);

// REQUEST HANDLING
void handleIn_request(int client_fd, request &req, std::vector<serverConf> &server_configs);
void handleOut_response(int client_fd, request &req);
void parse_request(const std::string &content, request &req);
void handle_GET(request &req);
void handle_POST(int client_fd, request &req);
void handle_DEL(request &req);

// CGIs
void call_GET_CGI(request &req);
void call_POST_CGI(const std::string &body, int client_fd);
void call_DEL_CGI();
void call_AUTOINDEX_CGI(request &req);

// PARSING REQUEST
std::string read_socket(int client_fd);
std::string read_boundary(const char *buffer);
std::string read_filename(const char *buffer);
std::string read_file(const std::string &path);
std::string read_session_id(const char *buffer);
std::string get_mime_type(const std::string &path);
std::string read_body(int client_fd, size_t content_length);
void check_full_body(const std::string &content, request &req);
void read_length(std::istringstream &stream, std::string &line, request &req);
void read_host(std::istringstream &stream, std::string &line, request &req);

// UTILS UPLOAD
void compose_file(request &req);
void upload_file(request &req);

// UTILS RESPONSES
void write_response200(int client_fd, int status, request &req, const std::string &content);
void write_response300(int client_fd, std::string redirect_infos);
void write_response400(int client_fd, int status, const std::string &err_file);
void write_response500(int client_fd, int status, const std::string &err_file);

// UTILS
void my_prints(std::string content, request &req);
void debug_content(const std::string &content);
void generate_session_id(request &req);
bool allowed_path(const std::string &path);

// PARSING CONFIG
std::vector<serverConf> parse_config(const std::string &config_file);
void find_server_conf(std::vector<serverConf> &server_configs, request &req);
void print_servers_info(const std::vector<serverConf> &servers);
void parse_error_page(const std::string &line, serverConf &server);
void parse_hostname(const std::string &line, serverConf &server);
void parse_server_name(const std::string &line, serverConf &server);
void parse_port(const std::string &line, serverConf &server);
void parse_max_file_size(const std::string &line, serverConf &server);
void parse_max_body_size(const std::string &line, serverConf &server);
std::string parse_location(const std::string &line);
std::string parse_route_root(const std::string &line);
std::string parse_redirection(const std::string &line);
void parse_autoindex(const std::string &line, serverConf &server);
void parse_default_page(const std::string &line, serverConf &server);
std::string parse_allowed_methods(const std::string &line);
bool is_directory(const std::string &path);
bool check_redirects(request &req);
void check_directories(request &req);
void check_rooting(request &req);
void handle_granted(int client_fd, request &req);
void handle_autoindex(int client_fd);
void server_checks(serverConf &server, std::ifstream &file);
bool is_valid_url(const std::string &url);

// SIGNAL HANDLING
void handle_signal(int signal);
