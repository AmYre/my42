/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_sign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:20:01 by amben-ha          #+#    #+#             */
/*   Updated: 2024/01/31 02:02:31 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strchr_sign(const char *s, int c)
{
	char	*str;
	int		i;

	if (!s)
		return (0);
	str = (char *)s;
	i = 0;
	if (!str[0] && !c)
		return (0);
	if (!*str)
		return (0);
	while (str[i] != (unsigned char)c)
	{
		if (str[i] == '\0' && c != '\0')
			return (0);
		i++;
	}
	if (i > 0 && str[i] == '=' && str[i - 1] == '+')
		return (2);
	return (1);
}
