/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:51:06 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/17 16:03:05 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_n_flag(char *str)
{
	int	i;

	i = 0;
	if (str[i] != '-')
		return (0);
	i++;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	if (str[i - 1] != 'n')
		return (0);
	return (1);
}

int	ft_echo(char **args)
{
	int	i;
	int	n_flag;
	int	j;

	if (!args[1])
	{
		printf("\n");
		return (0);
	}
	n_flag = check_n_flag(args[1]);
	i = 1 + n_flag;
	while (args[i] && check_n_flag(args[i]))
		i++;
	j = i;
	while (args[i])
	{
		if (i > j)
			printf(" ");
		printf("%s", args[i]);
		i++;
	}
	if (!n_flag)
		printf("\n");
	return (0);
}
