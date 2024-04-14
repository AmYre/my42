/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:34:14 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/19 19:36:14 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long	x;
	long long	signe;
	long long	res;

	res = 0;
	signe = 1;
	x = 0;
	while (str[x] != 0 && ((str[x] >= 9 && str[x] <= 13) || str[x] == 32))
		x++;
	if (str[x] == '+' || str[x] == '-')
	{
		if (str[x] == '-')
			signe *= -1;
		x++;
	}
	while (str[x] != 0 && (str[x] >= '0' && str[x] <= '9'))
	{
		res = (res * 10) + str[x] - '0';
		x++;
	}
	return (signe * res);
}
