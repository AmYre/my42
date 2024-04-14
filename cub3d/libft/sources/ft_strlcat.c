/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:05:20 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/06 15:41:58 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	x;
	size_t	y;
	size_t	z;

	x = 0;
	y = ft_strlen(src);
	z = ft_strlen((const char *)dest);
	if (!n)
		return (y + n);
	while (src[x] && z + x < n - 1)
	{
		dest[z + x] = src[x];
		x++;
	}
	if (n != 0 && n >= z)
		dest[z + x] = '\0';
	if (n < z)
		return (y + n);
	else
		return (y + z);
}
