/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:26:34 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 17:38:38 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	append_outfile(t_char_flag *redir_str, t_save_fd *standard)
{
	char	*str;
	int		fd;

	if (struct_to_char(&str, redir_str + 2))
		return (MALLOC_ERROR);
	fd = open(str, O_CREAT | O_RDWR | O_APPEND, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		perror("msh");
		free(str);
		return (PERMISSION_DENIED);
	}
	free(str);
	if (saved_standard_fd(standard, STDOUT))
	{
		close(fd);
		return (err_exec(DUP_ERROR, "dup", standard));
	}
	if (dup2(fd, STDOUT) == -1)
	{
		close(fd);
		return (err_exec(DUP_ERROR, "dup", standard));
	}
	close(fd);
	return (0);
}

static int	redirect_outfile(t_char_flag *redir_str, t_save_fd *standard)
{
	char	*str;
	int		fd;

	fd = 0;
	if (redir_str[1].c == '>')
		return (append_outfile(redir_str, standard));
	if (struct_to_char(&str, redir_str + 1))
		return (MALLOC_ERROR);
	fd = open(str, O_CREAT | O_TRUNC | O_RDWR, S_IRUSR | S_IWUSR);
	if (fd < 0)
	{
		perror("msh");
		free(str);
		return (PERMISSION_DENIED);
	}
	free(str);
	if (saved_standard_fd(standard, STDOUT) || dup2(fd, STDOUT) == -1)
	{
		close(fd);
		return (err_exec(DUP_ERROR, "dup", standard));
	}
	close(fd);
	return (0);
}

static int	redirect_heredoc(t_here_doc *fd_heredoc,
t_save_fd *standard, int *i)
{
	if (*i == 0)
	{
		while (fd_heredoc[*i].rank != START)
			(*i)++;
	}
	if (saved_standard_fd(standard, STDIN))
		return (err_exec(DUP_ERROR, "minish", standard));
	if (dup2(fd_heredoc[*i].fd[0], STDIN) == -1)
		return (err_exec(DUP_ERROR, "minish", standard));
	(*i)++;
	return (0);
}

static int	redirect_infile(t_save_fd *standard,
	t_char_flag *redir_str, t_here_doc *fd_heredoc, int *i)
{
	int		fd;
	char	*str;

	if (redir_str[1].c == '<')
		return (redirect_heredoc(fd_heredoc, standard, i));
	if (struct_to_char(&str, redir_str + 1))
		return (MALLOC_ERROR);
	if (check_file_exist(str, standard))
		return (EXEC_ERROR);
	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		err_exec(PERMISSION_DENIED, str, standard);
		free(str);
		return (EXEC_ERROR);
	}
	free(str);
	if (saved_standard_fd(standard, STDIN) || dup2(fd, STDIN) == -1)
	{
		close(fd);
		return (err_exec(DUP_ERROR, "minish", standard));
	}
	close(fd);
	return (0);
}

int	make_redirection(t_commands *all, t_pipe *pipefd, int *error)
{
	t_char_flag	*redir_str;
	t_list_word	*temp;
	int			i;

	i = 0;
	if (pipefd->prev[0] != 0 && !saved_standard_fd(&(all->fd_saved), STDIN)
		&& dup2(pipefd->prev[0], STDIN) == -1)
		return (*error |= err_exec(DUP_ERROR, "minish", &(all->fd_saved)));
	if (pipefd->next[1] != 0 && !saved_standard_fd(&(all->fd_saved), STDOUT)
		&& dup2(pipefd->next[1], STDOUT) == -1)
		return (*error |= err_exec(DUP_ERROR, "minish", &(all->fd_saved)));
	temp = all->parsed_redirect;
	while (temp)
	{
		redir_str = temp->str;
		if (redir_str[0].c == '<')
			*error |= redirect_infile(&(all->fd_saved),
					redir_str, all->fd_heredoc, &i);
		else
			*error |= redirect_outfile(redir_str, &(all->fd_saved));
		if (*error && (*error ^ SIMPLE_COMMAND))
			return (*error);
		temp = temp->next;
	}
	return (0);
}
