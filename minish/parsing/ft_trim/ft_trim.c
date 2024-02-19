/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:14:32 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/07 16:14:57 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_trim(t_commands *all)
{
	ft_trim_space(all->command);
	if (all->redirect[0].c != 0)
		ft_trim_space(all->redirect);
}

static void	replace_space(t_char_flag *line)
{
	while (line->c && is_space(line->c)
		&& (line->flag == 0 || line->flag == EXPAND))
		delete_char(line);
}

void	ft_trim_space(t_char_flag *line)
{
	int	i;

	i = 0;
	replace_space(line + 0);
	while (line[i].c)
	{
		if (is_space(line[i].c))
			replace_space(line + i + 1);
		i++;
	}
}
