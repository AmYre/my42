/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:29:35 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/07 23:49:12 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexes(t_stack *stack)
{
	t_stack	*current;
	int		median;
	int		i;

	i = 0;
	current = stack;
	if (!current)
		return ;
	median = ft_lstsize(stack) / 2;
	while (current)
	{
		current->index = i;
		if (i <= median)
			current->upper_half = 1;
		else
			current->upper_half = 0;
		current = current->next;
		i++;
	}
}

void	get_targets(t_data *data)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*target_node;

	current_a = data->stack_a;
	while (current_a)
	{
		data->best_match_index = LONG_MIN;
		current_b = data->stack_b;
		while (current_b)
		{
			if (current_b->value < current_a->value
				&& current_b->value > data->best_match_index)
			{
				data->best_match_index = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (data->best_match_index == LONG_MIN)
			current_a->target = get_biggest(data->stack_b);
		else
			current_a->target = target_node;
		current_a = current_a->next;
	}
}

void	set_costs(t_data *data)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		len_a;
	int		len_b;

	len_a = data->current_size_a;
	len_b = data->current_size_b;
	current_b = data->stack_b;
	current_a = data->stack_a;
	while (current_a)
	{
		current_a->cost = current_a->index;
		if (!(current_a->upper_half))
			current_a->cost = len_a - (current_a->index);
		if (current_a->target->upper_half)
			current_a->cost += current_a->target->index;
		else
			current_a->cost += len_b - (current_a->target->index);
		current_a = current_a->next;
	}
}

void	get_cheapest(t_data *data)
{
	t_stack	*current_a;
	t_stack	*cheapest;

	current_a = data->stack_a;
	cheapest = current_a;
	while (current_a)
	{
		if (current_a->cost < cheapest->cost)
			cheapest = current_a;
		current_a = current_a->next;
	}
	cheapest->is_cheapest = 1;
	data->cheapest = cheapest;
}
