/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:28:09 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/07 14:22:04 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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

int	ft_split_word(t_commands *all, int *error)
{
	if (ft_lstsplit(&(all->parsed_command), all->command, error))
		return (*error);
	if (ft_lstsplit(&(all->parsed_redirect), all->redirect, error))
		return (*error);
	return (0);
}
