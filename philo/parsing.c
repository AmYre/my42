/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 01:57:47 by amben-ha          #+#    #+#             */
/*   Updated: 2024/03/11 23:31:58 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_zero(char **argv)
{
	int	i;

	i = 1;
	while (i <= 4)
	{
		if (ft_atoi(argv[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (printf("Error: need 5/6 arguments\n"), 0);
	if (argc == 6 && ft_atoi(argv[5]) <= 0)
		return (printf("Error: nothing to eat\n"), 0);
	if (ft_atoi(argv[3]) > 2147483647 || ft_atoi(argv[4]) > 2147483647
		|| (argc == 6 && ft_atoi(argv[5]) > 2147483647))
		return (printf("Error: invalid argument\n"), 0);
	if (!check_zero(argv))
		return (printf("Error: invalid argument\n"), 0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (printf("Error: invalid argument\n"), 0);
			j++;
		}
		i++;
	}
	return (1);
}
