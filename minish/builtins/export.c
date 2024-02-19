/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:45:50 by amben-ha          #+#    #+#             */
/*   Updated: 2024/02/10 19:37:20 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_name(char **name, char *str, int *error, t_save_fd *standard)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (ft_isalnum(str[i]) || str[i] == '_')
		i++;
	if (i == 0 || (str[i] == '+' && str[i + 1] != '=')
		|| (str[i] != '+' && str[i] != '='))
	{
		restore_fd(standard, error);
		printf("minish : export: %s : not a valid identifier\n", str);
		return (1);
	}
	if (str[i - 1] == '+')
		i--;
	*name = ft_calloc(sizeof(char), i + 1);
	if (*name == 0)
		return (*error |= MALLOC_ERROR);
	while (j < i)
	{
		(*name)[j] = str[j];
		j++;
	}
	return (0);
}

static int	get_value(char *str, char **value, int *error)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] != '=' && str[i])
		i++;
	j = ++i;
	while (str[j])
		j++;
	*value = ft_calloc(sizeof(char), (j - i + 1));
	if (*value == 0)
		return (*error |= MALLOC_ERROR);
	j = 0;
	while (str[i])
	{
		(*value)[j] = str[i];
		i++;
		j++;
	}
	return (0);
}

static int	change_env(char *command, t_env *env, char *name, char *value)
{
	int	i;

	i = 0;
	while (command[i] && command[i] != '=')
		i++;
	while (env && ft_strncmp(env->key, name, ft_strlen(env->key)))
			env = env->next;
	if (command[i - 1] == '+')
	{
		if (ft_realloc(&(env->str), ft_strlen(env->str) + ft_strlen(value) + 1))
		{
			free(name);
			free(value);
			return (1);
		}
		ft_strcat(env->str, value);
		free(value);
	}
	else
	{
		free(env->str);
		env->str = value;
	}
	free(name);
	return (0);
}

static int	add_in_env(char *name, char *value, t_env **env, int *error)
{
	t_env	*test;

	test = *env;
	if (*env == 0)
	{
		*env = ft_lst_env(name, value);
		return (0);
	}
	while (test->next)
		test = test->next;
	test->next = ft_lst_env(name, value);
	if (test->next == 0)
	{
		free(name);
		free(value);
		return (*error |= MALLOC_ERROR);
	}
	return (0);
}

int	ft_export(char **command, t_env **env, int *error, t_save_fd *standard)
{
	char	*name;
	char	*value;

	if (!(*command))
		return (0);
	if (get_name(&name, *command, error, standard))
		return (1);
	if (get_value(*command, &value, error))
	{
		free(name);
		return (*error);
	}
	if (!in_env(name, *env))
		add_in_env(name, value, env, error);
	else if (change_env(*command, *env, name, value))
		return (*error |= MALLOC_ERROR);
	return (ft_export(command + 1, env, error, standard));
}
