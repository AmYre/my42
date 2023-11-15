/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:20:01 by amben-ha          #+#    #+#             */
/*   Updated: 2023/11/06 17:14:10 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	str = (char *)s;
	i = 0;
	if (!str[0] && !c)
		return (&str[i]);
	if (!*str)
		return (NULL);
	while (str[i] != (unsigned char)c)
	{
		if (str[i] == '\0' && c != '\0')
			return (NULL);
		i++;
	}
	return (&str[i]);
}
