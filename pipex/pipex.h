/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 17:30:44 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/05 22:28:32 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libs/libft/libft.h"
# include "./libs/printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_pipex
{
	pid_t	child_pid;
	int		argc;
	int		i;
	char	**argv;
	char	**env;
}	t_pipex;

typedef struct s_fds
{
	int		fd_io[2];
	int		fd_prev[2];
	int		fd_curr[2];
}	t_fds;

int		main(int argc, char **argv, char **env);
void	exec_cmd(char *cmd, char **env, t_fds *fds);
char	*find_cmd_path(char *cmd, char **env);
char	*create_path(char *cmd, char **path_split);

void	redirects(t_pipex *pipex, t_fds *fds);
void	redirect_first(t_fds *fds);
void	redirect_last(t_pipex *pipex, t_fds *fds);
void	clean(char *string, char **str, t_fds *fds);

void	check_args(int argc, char **argv, char **env);
void	init_pipex(t_pipex *pipex, int argc, char **argv, char **env);
void	init_fds(t_fds *fds, char *infile);
void	pipe_back(t_fds *fds);
void	close_fds(t_fds *fds);

#endif