/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_refill_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:10:57 by cjozefzo          #+#    #+#             */
/*   Updated: 2024/02/07 21:16:00 by cjozefzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_refill_t(int *size, int *size2, int n, t_char_flag *str)
{
	*size = n;
	*size2 = 0;
	while (str[*size2].c)
		(*size2)++;
}
