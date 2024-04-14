/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryounssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 18:45:46 by ryounssi          #+#    #+#             */
/*   Updated: 2022/06/14 16:46:09 by ryounssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	x;

	x = 0;
	if (str == NULL)
		return (0);
	while (str[x])
		x++;
	return (x);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*s;
	size_t		total;
	size_t		i;
	size_t		j;

	total = (ft_strlen(s1) + ft_strlen(s2));
	s = (char *)malloc(sizeof(char) * (total + 1));
	i = 0;
	if (s == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{	
			s[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
		s[i++] = s2[j++];
	s[total] = '\0';
	free(s1);
	return (s);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned char	c1;
	unsigned char	*s;
	unsigned int	x;

	x = 0;
	c1 = (unsigned char)c;
	s = (unsigned char *)str;
	if (!s)
		return (NULL);
	while (s[x] != '\0')
	{
		if (s[x] == c1)
			return ((char *)str + x);
		x++;
	}
	if (s[x] == c1)
		return ((char *)str + x);
	return (NULL);
}
