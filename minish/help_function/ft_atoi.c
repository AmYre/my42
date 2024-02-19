/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:20:48 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/08 23:55:58 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_int(long unsigned int *value, int signe)
{
	if (signe < 0 && *value > 2147483648)
	{
		*value = 0;
		return (0);
	}
	if (signe > 0 && *value > 2147483647)
	{
		*value = 0;
		return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	long unsigned int	result;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (check_int(&result, sign) && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}
