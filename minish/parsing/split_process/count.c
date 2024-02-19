/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:55:30 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:00:36 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	count_str(t_char_flag *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[j].c && (str[j].c == ' ' && str[j].flag == 0))
		j++;
	while (str[j + i].c && (str[j + i].c != '|' || str[j + i].flag != 0))
		i++;
	return (i);
}

int	count_command(t_char_flag *str)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i].c)
	{
		if (str[i].c == '|' && str[i].flag == 0)
			count++;
		i++;
	}
	return (count);
}

static int	count_char(t_char_flag *str, int *i, char a)
{
	int	count;

	count = 1;
	(*i)++;
	if (str[*i].c == a)
	{
		count++;
		(*i)++;
	}
	while (str[*i].c == ' ' && str[*i].flag == 0)
		(*i)++;
	while ((str[*i].c != '<' && str[*i].c != '>' && str[*i].c != '|'
			&& str[*i].c != ' ' && str[*i].c) || str[*i].flag != 0)
	{
		count++;
		(*i)++;
	}
	return (++count);
}

int	count_redirection(t_char_flag *str)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (str[i].c)
	{
		if (str[i].c == '>' && str[i].flag == 0)
			size += count_char(str, &i, '>');
		else if (str[i].c == '<' && str[i].flag == 0)
			size += count_char(str, &i, '<');
		else
			i++;
	}
	return (size);
}
