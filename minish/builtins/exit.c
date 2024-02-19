/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:07:39 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/09 22:01:25 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_exit(char c, int i)
{
	if (i == 0 && (c == '-' || c == '+'))
		return (1);
	return (is_num(c));
}

int	ft_exit(char **argv, t_commands *all)
{
	int	i;

	i = all->exit_status;
	all->handle_error(FREE_ALL, all, (t_pipe *)0);
	if (!argv[1])
		i = 0;
	else if (argv[2])
	{
		printf("msh: exit: too many argument\n");
		i = ft_atoi(argv[1]);
	}
	else
	{
		i = 0;
		while (argv[1][i] && is_exit(argv[1][i], i))
			i++;
		if (argv[1][i])
			printf("msh: exit: %s : numeric argument required\n", argv[1]);
		i = ft_atoi(argv[1]);
	}
	clean_env(all->env);
	free_char(argv);
	exit(i);
}
