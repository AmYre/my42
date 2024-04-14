/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 14:10:18 by ryounssi          #+#    #+#             */
/*   Updated: 2024/04/04 11:10:32 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_words_nbr(char const *s, char c)
{
	int	x;
	int	wnbr;

	x = 0;
	wnbr = 0;
	while (s[x])
	{
		while (s[x] == c && s[x])
			x++;
		if (s[x])
			wnbr++;
		while (s[x] != c && s[x])
			x++;
	}
	return (wnbr);
}

int	len_word(int start, int end)
{
	int	len;

	len = 0;
	while (start < end)
	{
		start++;
		len++;
	}
	return (len);
}

char	*word_str(char const *s, int start, int end)
{
	int		idx;
	int		len;
	char	*word;

	idx = 0;
	len = len_word(start, end);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (len > 0)
	{
		word[idx++] = s[start++];
		len--;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	x;
	int		start;

	x = 0;
	start = -1;
	split = malloc(sizeof(char *) * (check_words_nbr(s, c) + 1));
	if (split == 0 || s == 0)
		return (NULL);
	i = 0;
	while (x <= ft_strlen(s))
	{
		if (s[x] != c && start < 0)
			start = x;
		else if ((s[x] == c || x == ft_strlen(s)) && start >= 0)
		{
			split[i++] = word_str(s, start, x);
			start = -1;
		}
		x++;
	}
	split[i] = 0;
	return (split);
}
