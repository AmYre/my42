/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc_pipe.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:33:35 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/16 19:39:26 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_here_doc(t_char_flag *str)
{
	int	i;
	int	size;

	size = 1;
	i = 1;
	while (str[i].c)
	{
		if (str[i].c == '<' && str[i + 1].c == '<')
		{
			size++;
			i++;
		}
		i++;
	}
	return (size);
}

static int	realloc_here_doc(t_here_doc **fd_heredoc, t_char_flag *str)
{
	int			size;
	int			i;
	t_here_doc	*ret;

	i = 0;
	size = count_here_doc(str);
	ret = ft_calloc(sizeof(t_here_doc), size + 1);
	if (!ret)
		return (MALLOC_ERROR);
	while ((*fd_heredoc)[i].fd[0] > 0)
	{
		ret[i].fd[0] = (*fd_heredoc)[i].fd[0];
		ret[i].fd[1] = (*fd_heredoc)[i].fd[1];
		i++;
	}
	free(*fd_heredoc);
	*fd_heredoc = ret;
	return (0);
}

static int	count_actual_here_doc(t_here_doc *fd_heredoc)
{
	int	i;

	i = 0;
	while (fd_heredoc[i].fd[0] > 0)
		i++;
	return (i);
}

int	make_here_doc_pipe(t_commands *all, t_char_flag *str, int *error)
{
	static int	i = 0;

	if (!all->fd_heredoc)
	{
		*error ^= PIPE_LINE;
		return (make_here_doc(all, str, error));
	}
	if (i == 0)
	{
		i = count_actual_here_doc(all->fd_heredoc);
		if (count_here_doc(str) > 1)
			realloc_here_doc(&(all->fd_heredoc), str);
		if (i-- == 1)
			return (*error ^= PIPE_LINE);
	}
	else if (i-- > 0)
	{
		if (i == 0)
		{
			*error ^= PIPE_LINE;
			return (0);
		}
	}
	return (0);
}
