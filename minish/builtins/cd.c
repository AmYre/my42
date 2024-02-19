/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:50:53 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/17 16:52:47 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	error_msg_home(void)
{
	printf("minish: cd: no HOME no CHOCOLATE\n");
	return (11);
}

int	ft_cd(char **args, t_env *env, int *error, t_save_fd *standard)
{
	char	*path;

	if (restore_fd(standard, error))
		return (1);
	if (args[1] == NULL)
	{
		path = get_str_env("HOME", env);
		if (path == NULL)
			return (error_msg_home());
	}
	else if (args[2])
	{
		printf("minish: cd: too many arguments\n");
		return (1);
	}
	else
		path = args[1];
	if (chdir(path) == -1)
	{
		perror("minish: cd");
		return (1);
	}
	return (0);
}
