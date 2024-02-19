/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:20:01 by amben-ha          #+#    #+#             */
/*   Updated: 2024/01/31 02:02:36 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	if (!str[0] && !c)
		return (&str[i]);
	if (!*str)
		return (0);
	while (str[i] != (unsigned char)c)
	{
		if (str[i] == '\0' && c != '\0')
			return (0);
		i++;
	}
	return (&str[i]);
}
