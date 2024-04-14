/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 11:37:58 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 20:24:56 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	c1;
	unsigned char	*s;
	unsigned int	x;

	c1 = (unsigned char)c;
	s = (unsigned char *)str;
	x = ft_strlen(str);
	while (x > 0)
	{
		if (s[x] == c1)
			return ((char *)s + x);
		x--;
	}
	if (s[x] == c1)
		return ((char *)s + x);
	return (NULL);
}
