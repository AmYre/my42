/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:18:59 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:57 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_calloc(size_t nb, size_t size)
{
	size_t	i;
	size_t	a;
	char	*arr;

	i = 0;
	a = nb * size;
	if (size != 0 && a / size != nb)
		return (0);
	arr = malloc(nb * size);
	if (arr == 0)
		return (0);
	while (i < nb * size)
	{
		arr[i] = 0;
		i++;
	}
	return ((void *)arr);
}
