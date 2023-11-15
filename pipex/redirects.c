/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 01:32:27 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/12 23:10:05 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_fds(t_fds *fds)
{
	if (fds->fd_io[0] > 0)
		close(fds->fd_io[0]);
	if (fds->fd_io[1] > 0)
		close(fds->fd_io[1]);
	if (fds->fd_prev[0] > 0)
		close(fds->fd_prev[0]);
	if (fds->fd_prev[1] > 0)
		close(fds->fd_prev[1]);
	if (fds->fd_curr[0] > 0)
		close(fds->fd_curr[0]);
	if (fds->fd_curr[1] > 0)
		close(fds->fd_curr[1]);
}

void	redirect_first(t_fds *fds)
{
	if (dup2(fds->fd_io[0], STDIN_FILENO) < 0)
		return (perror("Dup2 failed"), close_fds(fds), exit(1));
	close(fds->fd_io[0]);
	if (dup2(fds->fd_curr[1], STDOUT_FILENO) < 0)
		return (perror("Dup2 failed"), close_fds(fds), exit(1));
}

void	redirect_last(t_pipex *pipex, t_fds *fds)
{
	fds->fd_io[1] = open(pipex->argv[pipex->argc - 1], O_WRONLY
			| O_CREAT | O_TRUNC, 0644);
	if (fds->fd_io[1] < 0)
		return (perror(pipex->argv[pipex->argc - 1]), exit(1));
	if (dup2(fds->fd_io[1], STDOUT_FILENO) < 0)
		return (perror("Dup2 failed"), close_fds(fds), exit(1));
	close(fds->fd_io[1]);
	if (dup2(fds->fd_prev[0], STDIN_FILENO) < 0)
		return (perror("Dup2 failed"), close_fds(fds), exit(1));
}

void	redirects(t_pipex *pipex, t_fds *fds)
{
	if (pipex->i == 0)
		redirect_first(fds);
	else if (pipex->i == pipex->argc - 4)
		redirect_last(pipex, fds);
	else
	{
		if (dup2(fds->fd_prev[0], STDIN_FILENO) < 0)
			return (perror("Dup2 failed"), close_fds(fds), exit(1));
		if (dup2(fds->fd_curr[1], STDOUT_FILENO) < 0)
			return (perror("Dup2 failed"), close_fds(fds), exit(1));
	}
	close_fds(fds);
	exec_cmd(pipex->argv[pipex->i + 2], pipex->env, fds);
}
