/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:12:32 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/07 02:38:23 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**splitted;
	int		vals[3];

	vals[0] = 0;
	vals[1] = 0;
	vals[2] = 0;
	if (!s)
		return (NULL);
	splitted = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!splitted)
		return (NULL);
	while (s[vals[0]])
	{
		if (s[vals[0]] != c)
		{
			vals[1] = vals[0];
			while (s[vals[0]] != c && s[vals[0]])
				vals[0]++;
			splitted[vals[2]++] = ft_substr(s, vals[1], vals[0] - vals[1]);
		}
		else
			vals[0]++;
	}
	splitted[vals[2]] = NULL;
	return (splitted);
}
