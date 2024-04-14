/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:06:39 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/23 19:10:27 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	x;
	unsigned int	i;
	char			*dup;
	char			*sr;

	x = 0;
	i = ft_strlen(s);
	sr = (char *)s;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (!sr || !f || !dup)
		return (NULL);
	while (x < i)
	{
		dup[x] = f(x, sr[x]);
		x++;
	}
	dup[x] = '\0';
	return (dup);
}
