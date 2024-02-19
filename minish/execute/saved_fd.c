/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saved_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:18:46 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:01:07 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	saved_standard_fd(t_save_fd *standard, int fd)
{
	if (fd == STDIN && standard->fd_stdin == -1)
	{
		if (standard->fd_stdin != -1)
			close(standard->fd_stdin);
		standard->fd_stdin = dup(STDIN);
		if (standard->fd_stdin == -1)
			return (DUP_ERROR);
	}
	if (fd == STDOUT && standard->fd_stdout == -1)
	{
		if (standard->fd_stdout != -1)
			close(standard->fd_stdout);
		standard->fd_stdout = dup(STDOUT);
		if (standard->fd_stdout == -1)
			return (DUP_ERROR);
	}
	return (0);
}
