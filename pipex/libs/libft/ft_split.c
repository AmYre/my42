/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:12:32 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/06 18:26:50 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char separator)
{
	int		count;
	int		inside_word;

	count = 0;
	while (*str)
	{
		inside_word = 0;
		while (*str == separator)
			++str;
		while (*str != separator && *str)
		{
			if (!inside_word)
			{
				++count;
				inside_word = 1;
			}
			++str;
		}
	}
	return (count);
}

static char	*get_next_word(char *str, char separator)
{
	static int	cursor = 0;
	char		*next_str;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (str[cursor] == separator)
		++cursor;
	while ((str[cursor + len] != separator) && str[cursor + len])
		++len;
	next_str = malloc((size_t)len * sizeof(char) + 1);
	if (!next_str)
		return (NULL);
	while ((str[cursor] != separator) && str[cursor])
		next_str[i++] = str[cursor++];
	next_str[i] = '\0';
	return (next_str);
}

char	**ft_split(char *str, char separator)
{
	int		total_words;
	char	**args_arr;
	int		i;

	if (!str)
		return (NULL);
	if (!separator)
		return (NULL);
	i = 0;
	total_words = count_words(str, separator);
	if (!total_words)
		return (NULL);
	args_arr = malloc(sizeof(char *) * (size_t)(total_words + 2));
	if (!args_arr)
		return (NULL);
	while (total_words-- >= 0)
		args_arr[i++] = get_next_word(str, separator);
	args_arr[i] = NULL;
	return (args_arr);
}
