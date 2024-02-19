/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:59:54 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/07 19:15:42 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_realloc(char **p, int size)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_calloc(sizeof(char), size);
	if (!ret)
		return (1);
	while ((*p)[i])
	{
		ret[i] = (*p)[i];
		i++;
	}
	free(*p);
	*p = ret;
	return (0);
}
