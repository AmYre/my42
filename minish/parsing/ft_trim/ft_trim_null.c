/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_null.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:33:58 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/10 17:13:17 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	delete_char(t_char_flag *line)
{
	int	i;

	i = 0;
	while (line[i].c)
	{
		line[i].c = line[i + 1].c;
		line[i].flag = line[i + 1].flag;
		i++;
	}
}

static void	replace_null(t_char_flag *line, int (separator)(char))
{
	int	i;

	i = 0;
	while (line[0].c && line[0].flag == CHAR_NULL && !separator(line[1].c))
		delete_char(line);
}

void	ft_trim_null(t_char_flag *line, int (separator)(char))
{
	int	i;

	i = 0;
	while (line[i].c)
	{
		if (line[i].flag == 3)
		{
			if (i == 0)
			{
				replace_null(line + i + 1, separator);
				if (line[i + 1].c)
					delete_char(line + i);
			}
			else if (line[i - 1].c != '<' && line[i - 1].c != '>'
				&& line[i - 1].flag == 0)
				delete_char(line + i);
		}
		i++;
	}
	replace_null(line + i, separator);
}
