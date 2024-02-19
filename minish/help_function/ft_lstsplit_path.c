/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:50:58 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/06 15:48:52 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_word(char *str, char *sep)
{
	int	size;
	int	i;

	size = 1;
	i = 0;
	while (str[i] == *sep)
		i++;
	while (str[i])
	{
		if (str[i] == *sep)
		{
			while (str[i] == *sep)
				i++;
			if (str[i])
				size++;
		}
		else
			i++;
	}
	return (size);
}

static char	*next_word(char *str, char *sep, int rank, int size_to_add)
{
	int		i;
	int		size;
	char	*ret;

	size = 0;
	i = 0;
	while (rank > 0)
	{
		if (str[i] == *sep)
			rank--;
		i++;
	}
	while (str[i] && str[i] != *sep)
	{
		size++;
		i++;
	}
	ret = ft_calloc(sizeof(char), size + 2 + size_to_add);
	if (ret == 0)
		return ((char *)0);
	ret[size] = '/';
	while (--size >= 0)
		ret[size] = str[--i];
	return (ret);
}

static char	**ret_error(int *error, int code)
{
	*error |= code;
	return ((char **)0);
}

char	**ft_lstsplit_path(char *str, char *sep, int size_to_add, int *error)
{
	int		i;
	int		size;
	char	**ret;

	if (str == 0)
		return (ret_error(error, COMMAND_NOT_EXIST));
	i = 0;
	size = count_word(str, sep);
	ret = ft_calloc(sizeof(char **), (size + 1));
	if (ret == 0)
		return (ret_error(error, MALLOC_ERROR));
	while (i < size)
	{
		ret[i] = next_word(str, sep, i, size_to_add);
		if (!ret[i])
		{
			free_char(ret);
			return (ret_error(error, MALLOC_ERROR));
		}
		i++;
	}
	return (ret);
}
