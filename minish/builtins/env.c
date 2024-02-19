/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:26:12 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/05 15:51:45 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_env(t_env *env, int *error)
{
	char	*to_print;

	while (env)
	{
		to_print = ft_calloc(sizeof(char),
				ft_strlen(env->key) + ft_strlen(env->str) + 2);
		if (to_print == 0)
			return (*error |= MALLOC_ERROR);
		ft_strcat(to_print, env->key);
		ft_strcat(to_print, "=");
		ft_strcat(to_print, env->str);
		printf("%s\n", to_print);
		free(to_print);
		env = env->next;
	}
	return (0);
}
