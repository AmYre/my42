/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:18:35 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 15:52:45 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	init_pipe(t_pipe *pipefd)
{
	pipefd->next[0] = 0;
	pipefd->next[1] = 0;
	pipefd->prev[0] = 0;
	pipefd->prev[1] = 0;
}

static void	init_struct(t_commands *all, int argc, char **argv)
{
	(void)argc;
	(void)argv;
	all->command = 0;
	all->redirect = 0;
	all->parsed_command = 0;
	all->parsed_redirect = 0;
	all->handle_error = err_t_command;
	all->fd_heredoc = 0;
	all->fd_saved.fd_stdin = -1;
	all->fd_saved.fd_stdout = -1;
	all->exit_status = 0;
}

static int	child_or_simple(t_commands *all, t_pipe *pipefd, int *error)
{
	if (expand(all, all->env, error))
	{
		all->handle_error(*error, all, pipefd);
		if ((*error & SIMPLE_COMMAND) != SIMPLE_COMMAND)
		{
			clean_env(all->env);
			close_all_fd(&(all->fd_heredoc), pipefd);
			exit(all->exit_status);
		}
		return (1);
	}
	execute(pipefd, all, error, all->env);
	all->handle_error(*error, all, pipefd);
	if ((*error & SIMPLE_COMMAND) != SIMPLE_COMMAND)
	{
		clean_env(all->env);
		close_all_fd(&(all->fd_heredoc), pipefd);
		exit(all->exit_status);
	}
	*error = 0;
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe		pipefd;
	t_commands	all;
	int			error;
	t_char_flag	*str;

	make_env(&all.env, envp);
	init_pipe(&pipefd);
	init_struct(&all, argc, argv);
	error = 0;
	while (1)
	{
		make_signal();
		if (line_read(&error, &str))
			return (all.handle_error(error, &all, &pipefd));
		if (parse(str, &all, &pipefd, &error) == PARENT)
		{
			if (!error || (error & EMPTY_LINE) == EMPTY_LINE)
				free(str);
			if ((error & PIPE_LINE) != PIPE_LINE)
				close_all_fd(&(all.fd_heredoc), &pipefd);
			continue ;
		}
		free(str);
		child_or_simple(&all, &pipefd, &error);
	}
}
