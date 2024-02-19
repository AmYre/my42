/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 14:03:27 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:56 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lstnew_env(char *str)
{
	t_env	*ret;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	ret = ft_calloc(sizeof(t_env), 1);
	ret->key = ft_calloc(sizeof(char), i + 1);
	if (ret->key == 0)
		return (0);
	ret->str = ft_calloc(sizeof(char), ft_strlen(str) + 1 - i);
	if (ret->str == 0)
		return (0);
	ft_strcpy(ret->str, &str[++i]);
	i = 0;
	while (str[i] != '=')
	{
		ret->key[i] = str[i];
		i++;
	}
	return (ret);
}
