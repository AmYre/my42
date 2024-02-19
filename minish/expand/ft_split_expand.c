/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:42:45 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:01:00 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*find_key(char *key, t_env *env)
{
	int	x;

	while (env)
	{
		x = 0;
		while (key[x] && env->key[x] && key[x] == env->key[x])
			x++;
		if (!key[x] && !env->key[x])
			return (env->str);
		env = env->next;
	}
	return (" \n\t");
}

static int	in(t_char_flag c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c.c == sep[i] && c.flag == EXPAND)
			return (1);
		i++;
	}
	return (0);
}

static int	count_word(t_char_flag *str, char *sep)
{
	int	i;
	int	size;

	size = 1;
	i = 0;
	while (str[i].c)
	{
		if (in(str[i], sep))
		{
			while (in(str[i], sep))
				i++;
			if (str[i].c)
				size++;
		}
		else
			i++;
	}
	return (size);
}

static int	word_size(t_char_flag *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i].c && !in(str[i], sep))
		i++;
	return (i);
}

int	ft_split_expand(t_list_word **list, t_env *env, int *error)
{
	char		*ifs;
	int			size;
	int			size_word;
	t_list_word	temp_list;

	size_word = 0;
	ifs = find_key("IFS", env);
	size = count_word((*list)->str, ifs);
	size_word = word_size((*list)->str, ifs);
	(*list)->str[size_word++].c = 0;
	temp_list = **list;
	while (size > 1)
	{
		while (in(*(temp_list.str + size_word), ifs))
			size_word++;
		temp_list.str = temp_list.str + size_word;
		size_word = word_size(temp_list.str, ifs);
		(*list)->next = ft_lstnew_word(temp_list.str, size_word);
		if ((*list)->next == 0)
			return (*error |= MALLOC_ERROR);
		(*list) = (*list)->next;
		size--;
	}
	(*list)->next = temp_list.next;
	return (0);
}
