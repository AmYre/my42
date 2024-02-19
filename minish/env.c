/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:48:29 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/07 20:20:25 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_str_env(char *key, t_env *env)
{
	if (!key[0])
		return ((char *)0);
	while (env)
	{
		if (!ft_strncmp(key, env->key, ft_strlen(key)))
			return (env->str);
		env = env->next;
	}
	return ((char *)0);
}

int	in_env(char *key, t_env *env)
{
	while (env)
	{
		if (!ft_strncmp(key, env->key, ft_strlen(key)))
			return (1);
		env = env->next;
	}
	return (0);
}

char	*key_find(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	while (str[i] == '_' || ft_isalpha(str[i]))
		i++;
	ret = ft_calloc(sizeof(char), i + 1);
	if (ret == 0)
		return ((char *)0);
	while (i--)
		ret[i] = str[i];
	return (ret);
}

void	make_env(t_env **final_env, char **envp)
{
	int		i;
	t_env	*new_env;

	i = 0;
	if (envp[i] != 0)
	{
		new_env = ft_lstnew_env(envp[i++]);
		if (new_env == 0)
			exit(MALLOC_ERROR);
		*final_env = new_env;
		while (envp[i])
		{
			new_env->next = ft_lstnew_env(envp[i]);
			if (new_env->next == 0)
				exit(clean_env(*final_env));
			new_env = new_env->next;
			i++;
		}
		return ;
	}
	*final_env = ft_lstnew_env("PATH=/usr/local/sbin:/usr/local/bin:"
			"/usr/sbin:/usr/bin:/sbin:/bin");
	if (final_env == 0)
		exit(MALLOC_ERROR);
}
