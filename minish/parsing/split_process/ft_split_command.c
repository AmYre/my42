/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:39:33 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/08 15:09:31 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	fill_command(t_commands *command, t_char_flag *str, int *error)
{
	int	i;
	int	j;

	(void)error;
	j = 0;
	i = 0;
	while (str[i].c && (str[i].c == ' ' && str[i].flag == 0))
		i++;
	while (str[i].c && (str[i].c != '|' || str[i].flag != 0))
	{
		command->command[j].c = str[i].c;
		command->command[j].flag = str[i].flag;
		i++;
		j++;
	}
	return (0);
}

static int	find_command(t_commands *all, int number, t_char_flag *str)
{
	int	i;
	int	j;
	int	start_here_doc;

	j = 0;
	start_here_doc = 0;
	i = 0;
	while (number && str[i].c)
	{
		if (str[i].c == '|' && str[i].flag == 0)
		{
			start_here_doc = j;
			number--;
		}
		if (str[i].c == '<' && str[i + 1].c == '<'
			&& !str[i].flag && !str[i + 1].flag)
			j++;
		i++;
	}
	if (all->fd_heredoc)
		all->fd_heredoc[start_here_doc].rank = START;
	return (i);
}

static int	parse_command(t_commands *all, int rank,
t_char_flag *str, t_pipe *pipefd)
{
	int	command;
	int	error;

	error = 0;
	command = find_command(all, rank, str);
	if (calloc_str(all, str + command, &error))
		return (all->handle_error(error, all, pipefd));
	if (fill_command(all, str + command, &error))
		return (all->handle_error(error, all, pipefd));
	if (calloc_redirection(all, &error))
		return (all->handle_error(error, all, pipefd));
	if (fill_redirection(all->command, all->redirect, &error))
		return (all->handle_error(error, all, pipefd));
	return (0);
}

static void	swap_pipe(t_pipe *pipefd)
{
	if (pipefd->prev[0])
	{
		close(pipefd->prev[0]);
		close(pipefd->prev[1]);
	}
	pipefd->prev[0] = pipefd->next[0];
	pipefd->prev[1] = pipefd->next[1];
	pipefd->next[0] = 0;
	pipefd->next[1] = 0;
}

int	ft_split_command(t_char_flag *str, t_commands *all,
		t_pipe *pipefd, pid_t *last_child)
{
	int		size;
	int		rank;

	rank = 0;
	size = count_command(str);
	command_handler();
	if (size == 1)
	{
		parse_command(all, rank, str, pipefd);
		return (-1);
	}
	if (pipe(pipefd->next))
		return (0);
	while (rank < size)
	{
		*last_child = fork();
		if (!(*last_child))
			return (parse_command(all, rank, str, pipefd));
		swap_pipe(pipefd);
		if (rank != size - 2 && (pipe(pipefd->next) || *last_child == -1))
			return (split_not_finished(rank));
		rank++;
	}
	return (size);
}
