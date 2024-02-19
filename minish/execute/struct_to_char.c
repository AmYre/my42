/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_to_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:48:43 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:01:06 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	struct_to_char(char **str, t_char_flag *to_transform)
{
	int		i;
	char	*ret;

	i = 0;
	while (to_transform[i].c)
		i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (ret == 0)
		return (MALLOC_ERROR);
	while (i >= 0)
	{
		if (to_transform[i].c == '0' && to_transform[i].flag == CHAR_NULL)
			ret[i] = 0;
		else
			ret[i] = to_transform[i].c;
		i--;
	}
	*str = ret;
	return (0);
}
