/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:14:55 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/04 11:12:05 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	x;
	size_t	y;

	x = start;
	y = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	else if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len >= ft_strlen(s))
		sub = malloc(sizeof(char) * ft_strlen(s) + 1);
	else
		sub = malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	while (x < ft_strlen(s) && y < len)
	{
		sub[y++] = s[x++];
	}
	sub[y] = '\0';
	return (sub);
}
