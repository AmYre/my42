/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:12:32 by amben-ha          #+#    #+#             */
/*   Updated: 2023/05/16 20:43:25 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_values(size_t *val)
{
	val[0] = 0;
	val[1] = 0;
	val[2] = 0;
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			i = j;
			count++;
		}
	}
	return (count);
}

char	**ft_split(const char *s, char c)
{
	char	**str;
	size_t	val[3];

	init_values(val);
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (0);
	while (s[val[0]])
	{
		if (s[val[0]] == c)
			val[0]++;
		else
		{
			val[1] = val[0];
			while (s[val[1]] && s[val[1]] != c)
				val[1]++;
			str[val[2]] = ft_substr(s, val[0], val[1] - val[0]);
			val[0] = val[1];
			val[2]++;
		}
	}
	str[val[2]] = 0;
	return (str);
}
