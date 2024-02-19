/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:58:22 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:38 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	calloc_str(t_commands *command, t_char_flag *str, int *error)
{
	int	size_str;

	size_str = count_str(str);
	command->command = ft_calloc(size_str + 2, sizeof(t_char_flag));
	if (command->command == 0)
		return (*error |= MALLOC_ERROR);
	return (0);
}

int	calloc_redirection(t_commands *command, int *error)
{
	int	size;

	size = count_redirection(command->command);
	command->redirect = ft_calloc(sizeof(t_char_flag), size + 2);
	if (command->redirect == 0)
		return (*error |= MALLOC_ERROR);
	return (0);
}
