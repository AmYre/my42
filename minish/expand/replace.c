/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 14:16:19 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/16 16:18:11 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_refill_null(t_char_flag *str, int i, int size_key)
{
	int	j;

	j = size_key;
	while (j--)
		delete_char(str + i - size_key);
	return (0);
}

static int	ft_refill_t(t_char_flag **str, char *to_insert, int i, int size_key)
{
	int			size;
	int			size2;
	t_char_flag	*temp;

	init_refill_t(&size, &size2, ft_strlen(to_insert), *str);
	temp = ft_calloc(sizeof(t_char_flag), size2 + size - size_key + 1);
	if (temp == 0)
		return (MALLOC_ERROR);
	while (size2 > i)
	{
		size2--;
		temp[size2 + size - size_key].c = (*str)[size2].c;
		temp[size2 + size - size_key].flag = (*str)[size2].flag;
	}
	while (size--)
	{
		temp[size2 + size - size_key].c = to_insert[size];
		temp[size2 + size - size_key].flag = EXPAND;
	}
	while ((size2-- - size_key) != 0)
		temp[size2 - size_key].c = (*str)[size2 - size_key].c;
	free(*str);
	*str = temp;
	return (0);
}

static char	*find_key(t_char_flag *str, t_env *env, int i, int size)
{
	int	j;
	int	x;

	while (env)
	{
		x = 0;
		j = i;
		while (env->key[x] && env->key[x] == str[j].c)
		{
			x++;
			j++;
		}
		if (x == size && !(env->key[x]))
			return (env->str);
		env = env->next;
	}
	return ((char *) 0);
}

static int	expand_exit_status(t_char_flag **str, int i, char *to_copy)
{
	int	ret;

	if (to_copy == 0)
		return (MALLOC_ERROR);
	ret = ft_refill_t(str, to_copy, i + 1, 2);
	free(to_copy);
	return (ret);
}

int	replace_in(t_char_flag **str, t_env *env, int *i, int *exit_status)
{
	int		j;
	char	*to_insert;

	j = (*i)++;
	if (!is_expendable((*str)[*i].c))
	{
		if ((*str)[*i].c == '0' && (*str)[*i].flag == 3)
			delete_char(&((*str)[*i - 1]));
		if ((*str)[*i].c == '?')
			return (expand_exit_status(str, *i, ft_itoa(*exit_status)));
		return (0);
	}
	while ((*str)[*i].c && (*str)[*i].flag == (*str)[j].flag
		&& is_expendable((*str)[*i].c))
		(*i)++;
	to_insert = find_key(*str, env, j + 1, *i - (j + 1));
	if (to_insert == 0)
		return (ft_refill_null(*str, *i, *i - j));
	else
	{
		if (ft_refill_t(str, to_insert, *i, *i - j))
			return (MALLOC_ERROR);
		*i += ft_strlen(to_insert) - *i + j;
	}
	return (0);
}
