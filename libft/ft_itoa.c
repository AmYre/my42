/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:51:21 by amben-ha          #+#    #+#             */
/*   Updated: 2023/05/16 22:46:10 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	nbr_length(int n)
{
	unsigned int	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	char			is_neg;
	unsigned int	length;

	is_neg = 0;
	if (n < 0)
		is_neg = 1;
	length = nbr_length(n);
	str = malloc(sizeof(char) * (length + 1));
	if (!str)
		return (0);
	str[length] = '\0';
	while (length)
	{
		if (n < 0)
			str[length -1] = -(n % 10) + '0';
		else
			str[length -1] = (n % 10) + '0';
		n /= 10;
		length--;
	}
	if (is_neg)
		str[length] = '-';
	return (str);
}
