/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:50:38 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 15:07:26 by cjozefzo         ###   ########.fr       */
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

static int	check_redirect_expand(t_list_word *redirect, int *error)
{
	int	i;
	int	sign;

	while (redirect)
	{
		i = 0;
		sign = FALSE;
		while (redirect->str[i].c)
		{
			if (redirect->str[i].c == '>' || redirect->str[i].c == '<')
				sign = TRUE;
			i++;
		}
		if ((sign == FALSE || redirect->str[i - 1].c == '<'
				|| redirect->str[i - 1].c == '>')
			&& redirect->str[i].flag != CHAR_NULL)
			return (*error |= REDIRECT);
		redirect = redirect->next;
	}
	return (0);
}

static void	check_str(t_list_word *list, t_list_word **start_list)
{
	int			i;
	t_list_word	*prev;

	i = 0;
	prev = *start_list;
	while (prev && prev == *start_list && !list->str[0].c)
	{
		*start_list = (*start_list)->next;
		prev = *start_list;
		free(list->str);
		free(list);
		list = prev;
	}
	while (list)
	{
		if (!list->str[0].c)
		{
			prev->next = list->next;
			free(list->str);
			free(list);
		}
		else
			prev = list;
		list = prev->next;
	}
}

int	expand(t_commands *all, t_env *env, int *error)
{
	if (expand_str(all->parsed_command, &(all->exit_status), error, env))
		return (*error);
	check_str(all->parsed_command, &(all->parsed_command));
	if (expand_str(all->parsed_redirect, &(all->exit_status), error, env))
		return (*error);
	if (check_redirect_expand(all->parsed_redirect, error))
	{
		all->exit_status = 1;
		return (*error);
	}
	return (0);
}
