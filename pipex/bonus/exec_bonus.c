/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:31:44 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/12 22:15:45 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	clean(char *string, char **str, t_fds *fds)
{
	int	i;

	if (fds)
		close_fds(fds);
	if (string)
		free(string);
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

char	*create_path(char *cmd, char **path_split)
{
	int		i;
	char	*path;
	char	*full_path;

	i = 0;
	while (path_split[i])
	{
		path = ft_strjoin(path_split[i], "/");
		if (!path)
			return (NULL);
		full_path = ft_strjoin(path, cmd);
		free(path);
		if (!full_path)
			return (free(path), NULL);
		if (access(full_path, F_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	clean(NULL, path_split, NULL);
	return (NULL);
}

char	*find_cmd_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	**path_split;
	char	*cmd_path;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = env[i];
		i++;
	}
	path_split = ft_split(path, ':');
	if (!path_split)
		return (NULL);
	cmd_path = create_path(cmd, path_split);
	if (!cmd_path)
		return (NULL);
	else
		return (cmd_path);
}

void	exec_cmd(char *cmd, char **env, t_fds *fds)
{
	char	**args;
	char	*path;
	int		i;

	i = 0;
	args = ft_split(cmd, ' ');
	if (!args)
		return (ft_printf("Split failed"), close_fds(fds), exit(1));
	if (!args[0])
		return (ft_printf("%s: command not found\n", args[0]),
			clean(NULL, args, fds), exit(1));
	path = find_cmd_path(args[0], env);
	if (!path)
		return (ft_printf("%s: command not found\n", args[0]),
			clean(path, args, fds), exit(1));
	while (args[i])
		i++;
	args[i -1] = NULL;
	if (execve(path, args, NULL) < 0)
		return (perror("Execve failed"), clean(path, args, fds), exit(1));
}
