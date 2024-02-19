/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:55:34 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/11 14:02:56 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*find_key(t_env *env, char *key)
{
	int	x;

	while (env)
	{
		x = 0;
		while (key[x] && key[x] == env->key[x])
			x++;
		if (!key[x] && !env->key[x])
			return (env->str);
		env = env->next;
	}
	return ((char *)0);
}

static int	check_slash_path(char *cmd, char **cmd_path, int *error)
{
	struct stat	dir;

	if (access(cmd, F_OK))
	{
		*error |= FILE_NOT_EXIST;
		return (*error |= COMMAND_NOT_EXIST);
	}
	if (access(cmd, X_OK | R_OK))
		return (*error |= PERMISSION_DENIED);
	stat(cmd, &dir);
	if (S_ISDIR(dir.st_mode))
		return (*error |= IS_DIR);
	*cmd_path = ft_strdup(cmd);
	if (*cmd_path == 0)
		return (*error |= MALLOC_ERROR);
	return (0);
}

static int	search_in_path(char **path, char *cmd, char **cmd_path, int *error)
{
	int			i;

	i = 0;
	if (!cmd[0])
		return (*error |= COMMAND_NOT_EXIST);
	while (path[i])
	{
		ft_strcat(path[i], cmd);
		if (access(path[i], F_OK) == 0)
			break ;
		i++;
	}
	if (!path[i])
		return (*error |= COMMAND_NOT_EXIST);
	if (access(path[i], R_OK | X_OK))
		return (*error |= PERMISSION_DENIED);
	*cmd_path = ft_strdup(path[i]);
	if (*cmd_path == 0)
		return (*error |= MALLOC_ERROR);
	return (0);
}

int	check_cmd_path(char **cmd, t_env *env, char **cmd_path, int *error)
{
	char	**path;
	int		i;

	i = 0;
	if (check_builtins(cmd[0]))
		return (0);
	while (cmd[0][i] && cmd[0][i] != '/')
		i++;
	if (cmd[0][i] && check_slash_path(cmd[0], cmd_path, error))
		return (*error);
	else if (!cmd[0][i])
	{
		path = ft_lstsplit_path(find_key(env, "PATH"), ":",
				ft_strlen(cmd[0]) + 1, error);
		if (path == 0)
			return (*error);
		if (search_in_path(path, cmd[0], cmd_path, error))
		{
			free_char(path);
			return (*error);
		}
		free_char(path);
	}
	return (0);
}
