/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 15:21:43 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 16:04:38 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_builtins(char *str)
{
	if (!ft_strncmp("echo", str, 4))
		return (1);
	if (!ft_strncmp("cd", str, 2))
		return (1);
	if (!ft_strncmp("pwd", str, 3))
		return (1);
	if (!ft_strncmp("export", str, 6))
		return (1);
	if (!ft_strncmp("unset", str, 5))
		return (1);
	if (!ft_strncmp("env", str, 3))
		return (1);
	if (!ft_strncmp("exit", str, 4))
		return (1);
	return (0);
}

int	call_builtins(char **cmd, t_commands *all, int *error)
{
	int	ret;

	ret = 0;
	builtins_handler();
	if (!ft_strncmp("echo", cmd[0], 4))
		ret = ft_echo(cmd);
	else if (!ft_strncmp("cd", cmd[0], 2))
		ret = ft_cd(cmd, all->env, error, &(all->fd_saved));
	else if (!ft_strncmp("pwd", cmd[0], 3))
		ret = ft_pwd(error);
	else if (!ft_strncmp("export", cmd[0], 6))
		ret = ft_export(cmd + 1, &all->env, error, &(all->fd_saved));
	else if (!ft_strncmp("unset", cmd[0], 5))
		ret = ft_unset(cmd + 1, &(all->env));
	else if (!ft_strncmp("env", cmd[0], 3))
		ret = ft_env(all->env, error);
	else if (!ft_strncmp("exit", cmd[0], 4))
	{
		if (printf("exit\n") && restore_fd(&(all->fd_saved), error))
			return (*error);
		ret = ft_exit(cmd, all);
	}
	all->exit_status = ret;
	free_char(cmd);
	return (ret);
}
