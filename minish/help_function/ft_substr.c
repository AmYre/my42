/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:01:19 by amben-ha          #+#    #+#             */
/*   Updated: 2024/01/31 02:30:36 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_substr(char *s, int start, int len)
{
	int			str_length;
	char		*new_str;
	int			i;

	i = 0;
	if (!s)
		return (0);
	str_length = ft_strlen(s);
	if (start > str_length)
		return (ft_strdup(""));
	if ((str_length - start) < len)
		new_str = (char *)malloc(sizeof(char) * ((str_length - start) + 1));
	else
		new_str = (char *)malloc(sizeof(char) * len + 1);
	if (!new_str)
		return (0);
	while (i < len && s[start])
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
