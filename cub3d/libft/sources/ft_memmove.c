/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:29:01 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 20:25:58 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned int	i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d <= s)
	{
		while (i < (unsigned int)n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (d > s)
	{
		while (i < (unsigned int)n)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	dest = (void *)d;
	return (dest);
}
