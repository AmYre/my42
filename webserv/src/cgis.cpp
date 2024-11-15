/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cgis.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 02:38:31 by amben-ha          #+#    #+#             */
/*   Updated: 2024/11/08 18:36:44 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "webserv.hpp"

void call_GET_CGI(request &req)
{
	pid_t pid = fork();
	if (pid == -1)
	{
		std::cerr << "Failed to fork" << std::endl;
		return;
	}

	if (pid == 0)
	{
		std::string path = "PATH_INFO=" + req.path;
		char *argv[] = {(char *)"node", (char *)"./cgi-bin/get-cgi.js", NULL};
		char *envp[] = {(char *)path.c_str(), NULL};

		execve("/usr/bin/node", argv, envp);
		std::cerr << "Failed to exec GET CGI script" << std::endl;
		exit(1);
	}
	else
		waitpid(pid, NULL, WNOHANG);
}

void call_POST_CGI(const std::string &body, int client_fd)
{
	int pipefd[2];
	if (pipe(pipefd) == -1)
	{
		std::cerr << "Failed to create pipe" << std::endl;
		return;
	}

	pid_t pid = fork();
	if (pid == -1)
	{
		std::cerr << "Failed to fork" << std::endl;
		return;
	}

	if (pid == 0)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN_FILENO);
		dup2(client_fd, STDOUT_FILENO);
		close(pipefd[0]);

		char *argv[] = {(char *)"node", (char *)"./cgi-bin/post-cgi.js", NULL};
		execve("/usr/bin/node", argv, NULL);

		std::cerr << "Failed to exec CGI script" << std::endl;
		exit(1);
	}
	else
	{
		close(pipefd[0]);
		int result = write(pipefd[1], body.c_str(), body.size());
		if (result <= 0)
			close(client_fd);
		close(pipefd[1]);
		waitpid(pid, NULL, WNOHANG);
	}
}

void call_DEL_CGI()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		std::cerr << "Failed to fork" << std::endl;
		return;
	}

	if (pid == 0)
	{
		char *argv[] = {(char *)"node", (char *)"./cgi-bin/del-cgi.js", NULL};
		char *envp[] = {NULL};

		execve("/usr/bin/node", argv, envp);
		std::cerr << "Failed to exec DEL CGI script" << std::endl;
		exit(1);
	}
	else
		waitpid(pid, NULL, WNOHANG);
}

void call_AUTOINDEX_CGI(request &req)
{
	pid_t pid = fork();
	if (pid == -1)
	{
		std::cerr << "Failed to fork" << std::endl;
		return;
	}

	if (pid == 0)
	{
		std::string dir = "DIR=" + req.path;
		char *argv[] = {(char *)"node", (char *)"./cgi-bin/autoindex-cgi.js", NULL};
		char *envp[] = {(char *)dir.c_str(), NULL};

		execve("/usr/bin/node", argv, envp);
		std::cerr << "Failed to exec AUTOINDEX CGI script" << std::endl;
		exit(1);
	}
	else
		waitpid(pid, NULL, WNOHANG);
}