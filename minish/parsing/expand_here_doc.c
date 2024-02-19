/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 17:16:24 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/10 18:51:25 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	find_norme(char *key, t_char_flag *str, int *size, int nb_null)
{
	key[*size] = str[*size + nb_null].c;
	(*size)++;
}

int	quote_in_del(t_char_flag *str)
{
	int	i;

	i = 0;
	while (str[i].c && ((str[i].c != '|' && str[i].c != '>' && str[i].c != ' '
				&& str[i].c != '<') || str[i].flag != 0))
	{
		if (str[i].flag == SQUOTE || str[i].flag == QUOTE
			|| str[i].flag == CHAR_NULL)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	close_fd_norme(int fd, int *file)
{
	close(fd);
	file[1] = -1;
}

int	normal_write(int fd, char *to_write, int *error)
{
	if (write(fd, to_write, ft_strlen(to_write)) == -1)
		return (*error |= PERMISSION_DENIED);
	if (write(fd, "\n", 1) == -1)
		return (*error |= PERMISSION_DENIED);
	return (0);
}

int	expand_here_doc(char *to_write, int *i, t_env *env, int fd)
{
	char	*save;
	char	*to_expand;
	int		j;

	j = 0;
	save = key_find(to_write + *i);
	if (!save)
		return (MALLOC_ERROR);
	to_expand = get_str_env(save, env);
	if (!to_expand && !(to_write[*i] == '_' || ft_isalpha(to_write[*i])))
		write(fd, "$", 1);
	else if (to_expand)
		write(fd, to_expand, ft_strlen(to_expand));
	else
		write(fd, "", 1);
	while (to_write[*i] && save[j] == to_write[*i])
	{
		j++;
		(*i)++;
	}
	free(save);
	return (0);
}
