/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:52:36 by ryounssi          #+#    #+#             */
/*   Updated: 2022/05/30 20:23:07 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*s;
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s1);
	j = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (i + j + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		s[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		s[j++] = s2[i];
		i++;
	}
	s[j] = '\0';
	return (s);
}
