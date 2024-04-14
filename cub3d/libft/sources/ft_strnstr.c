/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:07:43 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/23 18:50:41 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	z;

	x = 0;
	y = 0;
	z = ft_strlen(little);
	if (z == 0)
		return ((char *)big);
	while (big[x] && x < len)
	{
		y = 0;
		while (big[x + y] == little[y] && little[y] && x + y < len)
			y++;
		if (little[y] == '\0')
			return ((char *)&big[x]);
		x++;
	}
	return (NULL);
}
