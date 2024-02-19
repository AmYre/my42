/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:43:03 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/11 14:36:57 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_all_fd(t_here_doc **fd_heredoc, t_pipe *pipefd)
{
	int	i;

	i = 0;
	close_t_pipe(pipefd);
	if (*fd_heredoc)
	{
		while ((*fd_heredoc)[i].fd[0] > 0)
		{
			close((*fd_heredoc)[i].fd[0]);
			if ((*fd_heredoc)[i].fd[1] > 0)
				close((*fd_heredoc)[i].fd[1]);
			i++;
		}
		free(*fd_heredoc);
		*fd_heredoc = 0;
	}
}

int	handle_error(int *error)
{
	if ((*error & SYNTAX_ERROR) == SYNTAX_ERROR)
	{
		printf("bash: Syntax error\n");
		if ((*error & PIPE_LINE) == PIPE_LINE)
			*error ^= PIPE_LINE;
		*error ^= SYNTAX_ERROR;
		return (PARENT);
	}
	return (PARENT);
}

void	close_t_pipe(t_pipe *pipefd)
{
	if (pipefd != 0)
	{
		if (pipefd->prev[0])
		{
			close(pipefd->prev[0]);
			pipefd->prev[0] = 0;
			close(pipefd->prev[1]);
			pipefd->prev[1] = 0;
		}
		if (pipefd->next[0])
		{
			close(pipefd->next[0]);
			pipefd->next[0] = 0;
			close(pipefd->next[1]);
			pipefd->next[1] = 0;
		}
	}
}

int	free_char(char **to_free)
{
	int	i;

	i = 0;
	if (to_free != 0)
	{
		while (to_free[i] != 0)
		{
			free(to_free[i]);
			i++;
		}
		free(to_free);
	}
	return (0);
}

int	clean_env(t_env *envp)
{
	t_env	*to_free;

	to_free = envp;
	while (envp)
	{
		envp = envp->next;
		free(to_free->key);
		free(to_free->str);
		free(to_free);
		to_free = envp;
	}
	return (MALLOC_ERROR);
}
