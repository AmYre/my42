/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_to_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:43:17 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:01:11 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_size(t_env *env)
{
	int	size;

	size = 0;
	while (env)
	{
		size++;
		env = env->next;
	}
	return (size);
}

char	**env_to_char(t_env *env)
{
	char	**ret;
	int		size;
	int		i;

	i = 0;
	size = count_size(env);
	ret = ft_calloc(sizeof(char *), size + 1);
	if (ret == 0)
		return ((char **)0);
	while (env)
	{
		ret[i] = ft_calloc(sizeof(char), ft_strlen(env->str)
				+ ft_strlen(env->key) + 2);
		if (ret[i] == 0)
		{
			free_char(ret);
			return ((char **)0);
		}
		ft_strcat(ret[i], env->key);
		ft_strcat(ret[i], "=");
		ft_strcat(ret[i], env->str);
		env = env->next;
		i++;
	}
	return (ret);
}
