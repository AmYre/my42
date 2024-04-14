/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:31:37 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/25 16:03:39 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c1;
	unsigned char	*s;
	unsigned int	x;

	x = 0;
	c1 = (unsigned char)c;
	s = (unsigned char *)str;
	while (s[x] != '\0')
	{
		if (s[x] == c1)
			return ((char *)str + x);
		x++;
	}
	if (s[x] == c1)
		return ((char *)str + x);
	return (0);
}
