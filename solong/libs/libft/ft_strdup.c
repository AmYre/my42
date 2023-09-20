/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:34:17 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/19 02:27:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i])
		i++;
	res = (char *)malloc(sizeof(char) * i + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (src[i] && src[i] != '\n')
	{
		res[i] = src[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
