/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:10:31 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/24 14:37:56 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkset(char const *set, char c)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*s2;
	unsigned int	sx;
	unsigned int	ex;
	unsigned int	i;

	sx = 0;
	ex = ft_strlen(s1);
	while (s1[sx] && ft_checkset(set, s1[sx]))
		sx++;
	while (ex > sx && ft_checkset(set, s1[ex - 1]))
		ex--;
	s2 = (char *)malloc(sizeof(char) * (ex - sx + 1));
	i = 0;
	if (!s2)
		return (NULL);
	while (sx < ex)
	{
		s2[i] = s1[sx];
		sx++;
		i++;
	}
	s2[i] = '\0';
	free((char *)s1);
	return (s2);
}
