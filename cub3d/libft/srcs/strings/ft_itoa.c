/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:09:23 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/24 18:12:55 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(long long int n)
{
	int	len;

	len = 1;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_nchar(char *str, int len, long long int nl)
{
	int	start;

	start = 0;
	str[len] = '\0';
	len = len - 1;
	if (nl < 0)
	{
		nl *= -1;
		str[start] = '-';
		start = 1;
	}
	while (len >= start)
	{
		str[len] = (nl % 10) + '0';
		nl /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	long long int	nl;

	nl = n;
	len = ft_nlen(nl);
	if (nl < 0)
		len = len + 1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str = ft_nchar(str, len, nl);
	return (str);
}
