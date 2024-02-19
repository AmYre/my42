/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:30:57 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/17 15:55:20 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
/*uniquement dans le cas ou le pipe n'est pas fermer (ex : ls |) permet de
concatener l'ancienne structure avec la nouvelle string */
static int	ft_concat(t_char_flag **str, char *strin, int *error)
{
	int			size;
	int			i;
	t_char_flag	*temp;

	i = 0;
	while ((*str)[i].c)
		i++;
	size = ft_strlen(strin);
	temp = ft_calloc(size + i + 1, sizeof(t_char_flag));
	if (temp == 0)
		return (*error |= MALLOC_ERROR);
	temp[i + size].c = '\0';
	while (i + --size >= i)
		temp[i + size].c = strin[size];
	while (--i >= 0)
	{
		temp[i].c = (*str)[i].c;
		temp[i].flag = (*str)[i].flag;
	}
	free(*str);
	free(strin);
	*str = temp;
	return (0);
}

/*transforme la chaine de charactere renvoyer par read_line en une nouvelle
structure qui comprend des flags*/
static int	create_char_flag(t_char_flag **str, char *to_copy)
{
	int		size;

	size = ft_strlen(to_copy);
	*str = malloc(sizeof(t_char_flag) * (size + 1));
	if (str == 0)
		return (0);
	(*str)[size].c = '\0';
	(*str)[size].flag = 0;
	while (size--)
	{
		(*str)[size].c = to_copy[size];
		(*str)[size].flag = 0;
	}
	free(to_copy);
	return (1);
}

/*gere le cas ou le pipe n'a pas ete termine la boucle sert dans le cas ou
l'utilisateur n'a rien rentrer; les deux premiere conditions correspondent
respectivement au cas ou ctrl-d a ete rentrer; au cas ou ctrl-c a ete rentrer*/
static int	read_next(int *error, t_char_flag **str, char *temp)
{
	while ((*error & PIPE_LINE) == PIPE_LINE)
	{
		temp = readline(PIPE_PROMPT);
		if (temp)
			add_history(temp);
		if (temp == 0)
		{
			free(*str);
			return (*error |= EXIT);
		}
		if (temp[0] == 0)
		{
			free(temp);
			continue ;
		}
		return (ft_concat(str, temp, error));
	}
	return (0);
}

/* permet de récupérer la ligne entré par l'utilisateur 2 cas différent,
 cas simple dans le else et cas où le pipe
n'est pas fini (ex : "ls |"), dans le cas pipe non terminé la nouvelle string
est concaténer avec l'ancienne le tableau de flag aussi*/
int	line_read(int *error, t_char_flag **str)
{
	char	*temp;

	temp = NULL;
	if ((*error & PIPE_LINE) == PIPE_LINE)
		return (read_next(error, str, temp));
	temp = readline(PROMPT);
	if (temp)
		add_history(temp);
	if (temp == 0)
		return (*error |= EXIT);
	if (!create_char_flag(str, temp))
	{
		free(str);
		return (MALLOC_ERROR);
	}
	*error = 0;
	return (0);
}
