/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:21:49 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/05 14:28:46 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_lst_env(char *key, char *str)
{
	t_env	*ret;

	ret = malloc(sizeof(t_env));
	if (ret == 0)
		return ((t_env *)0);
	ret->key = key;
	ret->str = str;
	ret->next = 0;
	return (ret);
}
