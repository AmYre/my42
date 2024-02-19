/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:48:50 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 16:57:35 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	free_cmd(char **cmd, char *cmd_path, char **str_env)
{
	if (str_env)
		free_char(str_env);
	if (cmd)
		free_char(cmd);
	if (cmd_path)
		free(cmd_path);
}

static int	system_call_exec(char **cmd, char *cmd_path, char **str_env)
{
	default_handler();
	if (execve(cmd_path, cmd, str_env) == -1)
	{
		free_cmd(cmd, cmd_path, str_env);
		return (1);
	}
	return (0);
}

static int	simple_command(char **cmd, char *cmd_path,
char **str_env, int *error)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		return (*error |= FORK_ERROR);
	if (!child)
	{
		if (system_call_exec(cmd, cmd_path, str_env))
			return (1);
	}
	return (0);
}

int	execute_command(char **cmd, char *cmd_path, t_commands *all, int *error)
{
	char	**str_env;
	int		status;

	if (check_builtins(cmd[0]))
		return (call_builtins(cmd, all, error));
	str_env = env_to_char(all->env);
	if (str_env == 0)
		return (*error |= MALLOC_ERROR);
	if ((*error & SIMPLE_COMMAND) == SIMPLE_COMMAND)
	{
		if (simple_command(cmd, cmd_path, str_env, error))
			return (*error |= ERNO);
		if (waitpid(-1, &status, 0) == -1)
			return (*error |= ERNO);
		if (WIFEXITED(status))
			all->exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			all->exit_status = 128 + WTERMSIG(status);
	}
	else if (system_call_exec(cmd, cmd_path, str_env))
		return (*error |= ERNO);
	free_cmd(cmd, cmd_path, str_env);
	return (0);
}
