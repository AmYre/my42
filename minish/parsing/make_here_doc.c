/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:05:39 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/10 18:53:57 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	new_fd(t_here_doc *fd_heredoc, int *error, int **fd)
{
	int		i;

	i = 0;
	while (fd_heredoc[i].fd[0] > 0)
		i++;
	if (pipe(fd_heredoc[i].fd) == -1)
		return (*error |= PIPE_ERROR);
	*fd = &(fd_heredoc[i].fd[0]);
	return (0);
}

static int	find(char **key, t_char_flag *str)
{
	int	i;
	int	size;
	int	nb_null;

	nb_null = 0;
	i = 0;
	size = 0;
	while (str[i].c && ((str[i].c != '|' && str[i].c != '>' && str[i].c != ' '
				&& str[i].c != '<') || str[i].flag != 0))
		i++;
	*key = ft_calloc(sizeof(char), (i + 1));
	if (*key == 0)
		return (MALLOC_ERROR);
	while (size < i - nb_null)
	{
		if (str[size].flag == CHAR_NULL && i == 1)
			(*key)[size++] = 0;
		else if (str[size + nb_null].flag == CHAR_NULL)
			nb_null++;
		else
			find_norme(*key, str, &size, nb_null);
	}
	return (0);
}

static int	alloc(t_here_doc **fd_heredoc, t_char_flag *str)
{
	int	size;
	int	i;

	i = 1;
	size = 1;
	while (str[i].c)
	{
		if (str[i].c == '<' && str[i + 1].c == '<')
		{
			size++;
			i++;
		}
		i++;
	}
	*fd_heredoc = ft_calloc(sizeof(t_here_doc), size + 1);
	if (!*fd_heredoc)
		return (MALLOC_ERROR);
	(*fd_heredoc)[size].fd[0] = -1;
	return (0);
}

static int	write_to_heredoc(int fd, char *wrt, t_commands *all, int *error)
{
	int		i;

	i = 0;
	while (wrt[i])
	{
		if (wrt[i] == '$')
		{
			if (write(fd, wrt, i) == -1)
				return (*error |= PERMISSION_DENIED);
			i++;
			if (expand_here_doc(wrt, &i, all->env, fd))
				return (*error |= MALLOC_ERROR);
			wrt = wrt + i;
			i = 0;
		}
		else
			i++;
	}
	if (write(fd, wrt, i) == -1)
		return (*error |= PERMISSION_DENIED);
	if (write(fd, "\n", 1) == -1)
		return (*error |= PERMISSION_DENIED);
	return (0);
}

int	make_here_doc(t_commands *all, t_char_flag *str, int *error)
{
	char	*r;
	char	*key;
	int		*fd;

	if ((!all->fd_heredoc && alloc(&all->fd_heredoc, str)) || find(&key, str))
		return (*error |= MALLOC_ERROR);
	if (new_fd(all->fd_heredoc, error, &fd))
		return (*error);
	while (1)
	{
		r = readline(">");
		if (r == 0 || !ft_memcmp(r, key, ft_strlen(r) + 1))
			break ;
		if ((!quote_in_del(str) && write_to_heredoc(fd[1], r, all, error))
			|| (quote_in_del(str) && normal_write(fd[1], r, error)))
			return (*error);
		free(r);
	}
	close_fd_norme(fd[1], fd);
	if (r == 0)
		printf("warning : here-document delimited by eof (wanted '%s')\n", key);
	else
		free(r);
	free(key);
	return (0);
}
