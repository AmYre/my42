/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:41:03 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/16 16:46:52 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	wait_children(t_commands *all, pid_t last_child, int number,
	int *error)
{
	int	status;

	status = 0;
	while (number > 0)
	{
		if (waitpid(last_child, &status, 0) == -1)
			return (*error |= ERNO);
		if (last_child != -1)
		{
			if (WIFEXITED(status))
				all->exit_status = WEXITSTATUS(status);
			else if (WIFSIGNALED(status))
				all->exit_status = 128 + WTERMSIG(status);
			last_child = -1;
		}
		number--;
		if (!number)
			return (PARENT);
	}
	return (PARENT);
}

int	parse(t_char_flag *str, t_commands *all, t_pipe *pipefd, int *error)
{
	int			number_command;
	int			i;
	pid_t		last_child;

	i = 0;
	check_quote(str);
	if (check_syntax(all, str, error))
		return (handle_error(error));
	number_command = ft_split_command(str, all, pipefd, &last_child);
	if ((*error & MALLOC_ERROR) == MALLOC_ERROR)
		exit(all->handle_error(*error, all, pipefd));
	if (number_command > 0)
		return (wait_children(all, last_child, number_command, error));
	if (number_command < 0)
		*error |= SIMPLE_COMMAND;
	ft_trim(all);
	if (ft_split_word(all, error))
		all->handle_error(*error, all, pipefd);
	return (CHILD);
}
