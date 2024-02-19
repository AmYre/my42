/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 19:14:39 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:53 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_memcmp(void *s1, void *s2, unsigned int n)
{
	unsigned char	*d1;
	unsigned char	*d2;
	unsigned int	i;

	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (d1[i] < d2[i])
			return (-1);
		else if (d1[i] > d2[i])
			return (1);
		i++;
	}
	return (0);
}
