/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 21:34:52 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/02 23:45:16 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_data *data)
{
	t_stack	*biggest_a;

	biggest_a = get_biggest(data->stack_a);
	if (data->stack_a == biggest_a)
		rotate(&(data->stack_a), 'a');
	else if (data->stack_a->next == biggest_a)
		reverse_rotate(&(data->stack_a), 'a');
	if (data->stack_a->value > data->stack_a->next->value)
		swap_a(data);
}

void	complete_five(t_data *data, int middle)
{
	while (data->target_five != data->stack_a)
	{
		if (data->target_five->index < middle)
			rotate(&data->stack_a, 'a');
		else
			reverse_rotate(&data->stack_a, 'a');
	}
}

void	target_five(t_data *data)
{
	t_stack	*current;

	data->best_match_index = LONG_MAX;
	current = data->stack_a;
	while (current)
	{
		if (data->stack_b->value < current->value
			&& current->value < data->best_match_index)
		{
			data->best_match_index = current->value;
			data->target_five = current;
		}
		current = current->next;
	}
}

void	handle_five(t_data *data, int middle)
{
	t_stack	*smallest;
	t_stack	*biggest;

	smallest = get_smallest(data->stack_a);
	biggest = get_biggest(data->stack_a);
	if (data->stack_b->value < smallest->value
		|| data->stack_b->value > biggest->value)
		data->target_five = smallest;
	else
		target_five(data);
	complete_five(data, middle);
}

void	small_sort(t_data *data)
{
	t_stack	*smallest;

	push_b(data);
	push_b(data);
	push_b(data);
	set_indexes(data->stack_a);
	set_indexes(data->stack_b);
	handle_five(data, 1);
	push_a(data);
	set_indexes(data->stack_a);
	handle_five(data, 2);
	push_a(data);
	handle_five(data, 3);
	push_a(data);
	set_indexes(data->stack_a);
	smallest = get_smallest(data->stack_a);
	while (smallest != data->stack_a)
	{
		if (smallest->index < 2)
			rotate(&data->stack_a, 'a');
		else
			reverse_rotate(&data->stack_a, 'a');
	}
}
