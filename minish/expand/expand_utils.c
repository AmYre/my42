/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:47:59 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/07 02:44:50 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_expendable(char c)
{
	if (ft_isalnum(c) || c == '_' )
		return (1);
	return (0);
}

void	print_str(t_char_flag *str)
{
	int	i;

	i = 0;
	while (str[i].c)
	{
		printf("%c", str[i].c);
		i++;
	}
	printf("\n");
	i = 0;
	while (str[i].c)
	{
		printf("%d", str[i].flag);
		i++;
	}
	printf("\n");
}
