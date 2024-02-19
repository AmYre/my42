/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 15:46:33 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/16 19:29:33 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	check_pipe(t_char_flag *str, int i, int *error)
{
	i++;
	while (str[i].c && is_space(str[i].c))
		i++;
	if (str[i].c == '|' && str[i].flag == 0)
		return (*error |= SYNTAX_ERROR);
	if (!str[i].c)
		return (*error |= PIPE_LINE);
	return (0);
}

static int	check_r_redir(t_char_flag *str, int i, int *error)
{
	if (str[++i].c == '>')
		i++;
	while (str[i].c && is_space(str[i].c))
		i++;
	if ((str[i].c == '|' && str[i].flag == 0)
		|| (str[i].c == '>' && str[i].flag == 0)
		|| (str[i].c == '<' && str[i].flag == 0))
		return (*error |= SYNTAX_ERROR);
	if (!str[i].c)
		return (*error |= SYNTAX_ERROR);
	return (0);
}

static int	check_l_redir(t_commands *all, t_char_flag *str, int i, int *error)
{
	int	here;

	here = 0;
	if (str[++i].c == '<' && str[i].flag == 0)
	{
		here++;
		i++;
	}
	while (str[i].c && is_space(str[i].c))
		i++;
	if ((str[i].c == '|' && str[i].flag == 0)
		|| (str[i].c == '>' && str[i].flag == 0)
		|| (str[i].c == '<' && str[i].flag == 0))
		return (*error |= SYNTAX_ERROR);
	if (!str[i].c)
		return (*error |= SYNTAX_ERROR);
	if (here && (*error & PIPE_LINE) == PIPE_LINE)
	{
		if (make_here_doc_pipe(all, str + i, error))
			return (*error);
	}
	else if (here && make_here_doc(all, str + i, error))
		return (*error);
	return (0);
}

int	check_syntax(t_commands *all, t_char_flag *str, int *error)
{
	int	i;

	i = 0;
	while (is_space(str[i].c) && str[i].flag == 0)
		i++;
	if (!str[i].c)
		return (*error |= EMPTY_LINE);
	if (check_pipe(str, -1, error))
		return (1);
	while (str[i].c)
	{
		if (str[i].c == '|' && str[i].flag == 0 && check_pipe(str, i, error))
			return (1);
		else if (str[i].c == '>' && str[i].flag == 0
			&& check_r_redir(str, i, error))
			return (1);
		else if (str[i].c == '<' && str[i].flag == 0
			&& check_l_redir(all, str, i, error))
			return (1);
		i++;
	}
	if ((*error & PIPE_LINE) == PIPE_LINE)
		*error ^= PIPE_LINE;
	return (0);
}
