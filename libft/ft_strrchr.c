/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:44:32 by amben-ha          #+#    #+#             */
/*   Updated: 2023/05/15 20:13:08 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = ft_strlen(str);
	if (c == 0 && s)
		return (&str[i]);
	while (i--)
		if (str[i] == (unsigned char)c)
			return (&str[i]);
	if (c == 0)
		return (&str[i +1]);
	return (0);
}
