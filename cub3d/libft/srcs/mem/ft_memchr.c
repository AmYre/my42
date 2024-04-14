/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:28:29 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 20:27:02 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c1;
	unsigned int	i;

	i = 0;
	c1 = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < (unsigned int)n)
	{
		if (str[i] == c1 && i < (unsigned int)n)
			return (str + i);
		i++;
	}
	return (NULL);
}
