/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 15:44:58 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/11 13:49:42 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	restore_fd(t_save_fd *standard, int *error)
{
	if (standard->fd_stdin >= 0)
	{
		if (dup2(standard->fd_stdin, STDIN) == -1)
			return (*error |= DUP_ERROR);
		close(standard->fd_stdin);
		standard->fd_stdin = -1;
	}
	if (standard->fd_stdout >= 0)
	{
		if (dup2(standard->fd_stdout, STDOUT) == -1)
			return (*error |= DUP_ERROR);
		close(standard->fd_stdout);
		standard->fd_stdout = -1;
	}
	return (0);
}

static int	make_cmd(t_list_word *list, char ***ret, int *error)
{
	int		size;
	int		i;

	i = 0;
	size = ft_lstsize(list);
	*ret = ft_calloc(sizeof(char **), size + 1);
	if (*ret == 0)
		return (*error |= MALLOC_ERROR);
	while (list)
	{
		if (struct_to_char(*ret + i, list->str))
		{
			free_char(*ret);
			return (*error |= MALLOC_ERROR);
		}
		i++;
		list = list->next;
	}
	return (0);
}

static void	free_all(char **cmd, char *cmd_path)
{
	free_char(cmd);
	if (cmd_path)
		free(cmd_path);
}

static int	execute_error(char **cmd, char *cmd_path,
	t_commands *all, int *error)
{
	if (restore_fd(&(all->fd_saved), error))
	{
		free_all(cmd, cmd_path);
		return (*error);
	}
	if ((*error & COMMAND_NOT_EXIST) == COMMAND_NOT_EXIST)
	{
		all->exit_status = 127;
		if ((*error & FILE_NOT_EXIST) == FILE_NOT_EXIST)
			printf("minish : %s : no such file or directory\n", cmd[0]);
		else
			printf("minish : %s : command not found\n", cmd[0]);
	}
	if ((*error & PERMISSION_DENIED) == PERMISSION_DENIED)
	{
		all->exit_status = 126;
		printf("minish : %s : permission denied\n", cmd[0]);
	}
	if ((*error & IS_DIR) == IS_DIR)
	{
		all->exit_status = 126;
		printf("minish : %s : is a directory\n", cmd[0]);
	}
	free_all(cmd, cmd_path);
	return (0);
}

int	execute(t_pipe *pipefd, t_commands *all, int *error, t_env *env)
{
	char	**cmd;
	char	*cmd_path;

	cmd = 0;
	cmd_path = 0;
	if (make_redirection(all, pipefd, error))
		return (restore_fd(&(all->fd_saved), error));
	if (!all->command->c || !all->parsed_command)
		return (restore_fd(&(all->fd_saved), error));
	if (make_cmd(all->parsed_command, &cmd, error))
		return (restore_fd(&(all->fd_saved), error));
	if (check_cmd_path(cmd, env, &cmd_path, error))
		return (execute_error(cmd, cmd_path, all, error));
	close_all_fd(&(all->fd_heredoc), pipefd);
	all->fd_heredoc = 0;
	if (execute_command(cmd, cmd_path, all, error))
		return (restore_fd(&(all->fd_saved), error));
	if (restore_fd(&(all->fd_saved), error))
		return (*error);
	return (*error |= FREE_ALL);
}
