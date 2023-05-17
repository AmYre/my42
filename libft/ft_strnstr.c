/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:33:23 by amben-ha          #+#    #+#             */
/*   Updated: 2023/05/15 21:35:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	str = (char *)big;
	i = 0;
	if (!len && little[i])
		return (0);
	if (!little[i])
		return (str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == little[j] && (i + j) < len)
		{
			if (!little[j + 1])
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
