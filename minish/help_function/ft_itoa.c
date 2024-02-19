/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:51:48 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 17:27:30 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_size(int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int number)
{
	char	*ret;
	int		size;

	size = count_size(number);
	ret = ft_calloc(sizeof(char), size + 1);
	if (ret == 0)
		return ((char *)0);
	if (number == 0)
	{
		ret[0] = '0';
		return (ret);
	}
	size--;
	while (number)
	{
		ret[size] = number % 10 + '0';
		number /= 10;
		size--;
	}
	return (ret);
}
