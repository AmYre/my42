/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:45:14 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:50 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strdup(char *s)
{
	char	*r;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s[size] != 0)
		size++;
	r = malloc((size + 1) * sizeof(char));
	if (r == 0)
		return (0);
	while (s[i])
	{
		r[i] = s[i];
		i++;
	}
	r[i] = 0;
	return (r);
}
