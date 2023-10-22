/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 13:49:33 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/02 21:51:30 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_data *data)
{
	t_stack	*tmp;

	if (data->stack_a)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		if (data->stack_a)
			data->stack_a->prev = NULL;
		tmp->next = NULL;
		if (data->stack_b)
			data->stack_b->prev = tmp;
		tmp->next = data->stack_b;
		data->stack_b = tmp;
	}
	data->current_size_a--;
	data->current_size_b++;
	write(1, "pb\n", 3);
}

void	push_a(t_data *data)
{
	t_stack	*tmp;

	if (data->stack_b)
	{
		tmp = data->stack_b;
		data->stack_b = data->stack_b->next;
		if (data->stack_b)
			data->stack_b->prev = NULL;
		tmp->next = NULL;
		if (data->stack_a)
			data->stack_a->prev = tmp;
		tmp->next = data->stack_a;
		data->stack_a = tmp;
	}
	write(1, "pa\n", 3);
}

void	swap_a(t_data *data)
{
	t_stack	*tmp;

	if (data->stack_a && data->stack_a->next)
	{
		tmp = data->stack_a;
		data->stack_a = data->stack_a->next;
		tmp->next = data->stack_a->next;
		data->stack_a->next = tmp;
		data->stack_a->prev = NULL;
		tmp->prev = data->stack_a;
	}
	write(1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	t_stack	*top;
	t_stack	*second;

	top = data->stack_b;
	second = top->next;
	if (top && second)
	{
		top->next = second->next;
		second->next = top;
		second->prev = NULL;
		top->prev = second;
		data->stack_b = second;
	}
	write(1, "sb\n", 3);
}
