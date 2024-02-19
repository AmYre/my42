/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_t_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:10:12 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/10 19:29:27 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	clean_list(t_list_word **start)
{
	t_list_word	*to_free;

	to_free = *start;
	while (*start)
	{
		(*start) = (*start)->next;
		free(to_free->str);
		free(to_free);
		to_free = *start;
	}
}

static void	clean(t_commands *p, t_pipe *pipefd)
{
	if (p->parsed_command != 0)
		clean_list(&(p->parsed_command));
	if (p->parsed_redirect != 0)
		clean_list(&(p->parsed_redirect));
	if (p->command != 0)
		free(p->command);
	if (p->redirect != 0)
		free(p->redirect);
	close_all_fd(&(p->fd_heredoc), pipefd);
	p->command = 0;
	p->redirect = 0;
	p->fd_heredoc = 0;
	p->parsed_command = 0;
	p->parsed_redirect = 0;
	p->fd_heredoc = 0;
}

int	err_t_command(int err, t_commands *p, t_pipe *pipefd)
{
	clean(p, pipefd);
	if ((err & MALLOC_ERROR) == MALLOC_ERROR)
		malloc_err(p);
	else if ((err & FREE_ALL) == FREE_ALL)
		clean(p, pipefd);
	else if ((err & EXIT) == EXIT)
		exit_d(p);
	else if ((err & EXEC_ERROR) == EXEC_ERROR)
		p->exit_status = 1;
	else if ((err & PERMISSION_DENIED) == PERMISSION_DENIED)
		p->exit_status = 1;
	else if ((err & REDIRECT) == REDIRECT)
		redirect_err(p);
	else if ((err & AMBIGUOUS_REDIRECT) == AMBIGUOUS_REDIRECT)
		printf("ambiguous redirect2\n");
	else if ((err & ERNO) == ERNO)
		erno_d(p);
	else if ((err & DUP_ERROR) == DUP_ERROR)
		dup_d(p);
	else if ((err & PWD_ERROR) == PWD_ERROR)
		perror("msh");
	return (0);
}
