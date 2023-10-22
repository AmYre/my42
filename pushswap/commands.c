/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:34:21 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/02 21:53:25 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_data *data)
{
	while (data->stack_b != data->cheapest->target
		&& data->stack_a != data->cheapest)
		rr(data);
}

void	reverse_rotate_both(t_data *data)
{
	while (data->stack_b != data->cheapest->target
		&& data->stack_a != data->cheapest)
		rrr(data);
}

void	complete_rotations(t_data *data)
{
	while (data->stack_b != data->cheapest->target)
	{
		if (data->cheapest->target->upper_half)
			rotate(&data->stack_b, 'b');
		else
			reverse_rotate(&data->stack_b, 'b');
	}
	while (data->stack_a != data->cheapest)
	{
		if (data->cheapest->upper_half)
			rotate(&data->stack_a, 'a');
		else
			reverse_rotate(&data->stack_a, 'a');
	}
}
