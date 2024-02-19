/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:58:40 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 14:59:54 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// static void	print_lst(t_list_word *list)
// {
// 	int	i;

// 	while (list)
// 	{
// 		i = 0;
// 		while (list->str[i].c)
// 		{
// 			printf("%c", list->str[i].c);
// 			i++;
// 		}
// 		printf(";");
// 		list = list->next;
// 	}
// 	printf("\n");
// }

// static void	delete_arg(t_list_word *prev,
//t_list_word *to_delete, t_list_word **start_list)
// {
// 	if (prev == to_delete)
// 	{
// 		*start_list = prev->next;
// 		free(to_delete->str);
// 		free(to_delete);
// 	}
// 	prev = to_delete->next;
// 	free(to_delete->str);
// 	free(to_delete);
// }

static int	check_if_here_doc(t_list_word *list, int i)
{
	if (i < 2)
		return (1);
	if (i > 1)
	{
		if (list->str[i - 1].c == '<' && list->str[i - 1].flag != QUOTE
			&& list->str[i - 2].c == '<' && list->str[i - 2].flag != QUOTE)
			return (0);
	}
	return (1);
}

int	expand_str(t_list_word *list, int *exit_status, int *error, t_env *env)
{
	int			i;
	t_list_word	*prev;

	prev = list;
	while (list)
	{
		i = 0;
		ft_trim_null(list->str, is_space);
		while (list->str[i].c)
		{
			if (list->str[i].c == '$' && list->str[i].flag != SQUOTE
				&& check_if_here_doc(list, i))
				replace_in(&(list->str), env, &i, exit_status);
			else
				i++;
			ft_trim_null(list->str, is_space);
		}
		ft_split_expand(&list, env, error);
		if ((*error & MALLOC_ERROR) == MALLOC_ERROR)
			return (*error);
		prev = list;
		list = list->next;
	}
	return (0);
}
