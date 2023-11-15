/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:27:36 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/13 00:11:10 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_args(int argc, char **argv, char **env)
{
	char	*path;
	int		i;

	if (argc != 5)
		return (ft_printf("Takes 4 arguments\n"), exit(1));
	i = 0;
	while (i < argc - 3)
	{
		if (!ft_strlen(argv[i + 2]))
			return (ft_printf("command not found\n"), exit(1));
		i++;
	}
	path = NULL;
	if (!env)
		return (ft_printf("Env not found\n"), exit(1));
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			path = env[i];
		i++;
	}
	if (!path)
		return (ft_printf("PATH not found\n"), exit(1));
}

void	init_fds(t_fds *fds, char *infile)
{
	fds->fd_io[0] = -1;
	fds->fd_io[1] = -1;
	fds->fd_prev[0] = -1;
	fds->fd_prev[1] = -1;
	fds->fd_curr[0] = -1;
	fds->fd_curr[1] = -1;
	fds->fd_io[0] = open(infile, O_RDONLY);
	if (fds->fd_io[0] < 0)
		return (perror(infile), exit(1));
	if (pipe(fds->fd_prev) < 0)
		return (perror("Pipe failed"),
			close_fds(fds), exit(1));
}

void	pipe_back(t_fds *fds)
{
	close(fds->fd_prev[0]);
	close(fds->fd_prev[1]);
	fds->fd_prev[0] = fds->fd_curr[0];
	fds->fd_prev[1] = fds->fd_curr[1];
}

void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env)
{
	pipex->env = env;
	pipex->argc = argc;
	pipex->argv = argv;
}

int	main(int argc, char **argv, char **env)
{
	static t_pipex	pipex = {0};
	t_fds			fds;

	check_args(argc, argv, env);
	init_pipex(&pipex, argc, argv, env);
	init_fds(&fds, argv[1]);
	while (pipex.i < argc - 3)
	{
		if (pipe(fds.fd_curr) < 0)
			return (perror("Pipe failed"), close_fds(&fds), 1);
		pipex.child_pid = fork();
		if (pipex.child_pid < 0)
			return (perror("Fork failed"), close_fds(&fds), 1);
		else if (pipex.child_pid == 0)
			redirects(&pipex, &fds);
		else
			pipe_back(&fds);
		pipex.i++;
	}
	close_fds(&fds);
	pipex.i = 0;
	while (pipex.i < argc - 3)
		waitpid(pipex.i++, NULL, 0);
	return (0);
}
