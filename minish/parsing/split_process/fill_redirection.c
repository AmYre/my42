/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:10:30 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/01/31 01:30:32 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	copy_char(t_char_flag *redirection, t_char_flag *command,
				int *i, int *j)
{
	int	x;

	x = 0;
	redirection[*j].c = command[*i].c;
	redirection[*j].flag = command[*i].flag;
	(*j)++;
	while (command[(*i) + x].c)
	{
		command[(*i) + x].c = command[(*i) + x + 1].c;
		command[(*i) + x].flag = command[(*i) + x + 1].flag;
		x++;
	}
}

static void	fill_char(t_char_flag *str, t_char_flag *redirect, int *i, int *j)
{
	copy_char(redirect, str, i, j);
	if ((str[*i].c == '<' || str[*i].c == '>') && str[*i].flag == 0)
		copy_char(redirect, str, i, j);
	while (str[*i].c == ' ' && str[*i].flag == 0)
		(*i)++;
	while ((str[*i].c != '<' && str[*i].c != '>' && str[*i].c != '|'
			&& str[*i].c != ' ' && str[*i].c) || str[*i].flag != 0)
		copy_char(redirect, str, i, j);
	redirect[*j].c = ' ';
	(*j)++;
}

int	fill_redirection(t_char_flag *str, t_char_flag *redirect, int *error)
{
	int	i;
	int	j;

	(void)error;
	j = 0;
	i = 0;
	while (str[i].c)
	{
		if (str[i].c == '>' && str[i].flag == 0)
			fill_char(str, redirect, &i, &j);
		else if (str[i].c == '<' && str[i].flag == 0)
			fill_char(str, redirect, &i, &j);
		else
			i++;
	}
	return (0);
}
