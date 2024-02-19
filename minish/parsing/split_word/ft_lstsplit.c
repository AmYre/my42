/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:57:01 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:32 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_list_word	*ft_lstnew_word(t_char_flag *str, int size)
{
	t_list_word	*ret;
	int			i;

	i = 0;
	ret = ft_calloc(1, sizeof(t_list_word));
	if (ret == 0)
		return ((t_list_word *)0);
	ret->str = ft_calloc(size + 1, sizeof(t_char_flag));
	if (ret->str == 0)
	{
		free(ret);
		return ((t_list_word *)0);
	}
	while (i < size)
	{
		ret->str[i].c = str[i].c;
		ret->str[i].flag = str[i].flag;
		i++;
	}
	ret->str[i].c = '\0';
	ret->next = 0;
	return (ret);
}

static int	count_word(t_char_flag *str)
{
	int	count;

	count = 0;
	while (str[count].c && (!is_space(str[count].c) || str[count].flag != 0))
		count++;
	return (count);
}

int	ft_lstsplit(t_list_word **list, t_char_flag *str, int *error)
{
	t_list_word	*temp;
	int			i;
	int			size;

	size = count_word(str);
	if (size == 0)
		return (0);
	*list = ft_lstnew_word(str, size);
	temp = *list;
	if (list == 0)
		return (*error |= MALLOC_ERROR);
	i = size + 1;
	while (str[i].c)
	{
		size = count_word(str + i);
		temp->next = ft_lstnew_word(str + i, size);
		if (temp->next == 0)
			return (*error |= MALLOC_ERROR);
		i += size + 1;
		temp = temp->next;
	}
	return (0);
}
