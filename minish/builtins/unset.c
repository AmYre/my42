/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:34:57 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/05 14:41:37 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	search_and_unset(char *name, t_env **env)
{
	t_env	*prev;
	t_env	*temp;

	temp = *env;
	prev = temp;
	while (temp)
	{
		if (!ft_strncmp(name, temp->key, ft_strlen(name)))
			break ;
		prev = temp;
		temp = temp->next;
	}
	if (prev == temp)
		*env = (*env)->next;
	else
		prev->next = temp->next;
	free(temp->key);
	free(temp->str);
	free(temp);
}

int	ft_unset(char **name, t_env **env)
{
	int		i;

	i = 0;
	while (name[i])
	{
		if (!in_env(name[i], *env))
		{
			i++;
			continue ;
		}
		search_and_unset(name[i], env);
		i++;
	}
	return (0);
}
