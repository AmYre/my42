/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:00:16 by amben-ha          #+#    #+#             */
/*   Updated: 2023/05/15 21:23:59 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	dst_length;
	size_t	src_length;

	i = 0;
	if (!size)
		return (ft_strlen(src));
	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (size <= dst_length)
		return (src_length + size);
	while (src[i] && (dst_length + i) < (size - 1))
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (src_length + dst_length);
}
