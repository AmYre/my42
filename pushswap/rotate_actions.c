/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:37:01 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/02 22:01:25 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_data *data)
{
	rotate_nowrite(&data->stack_a);
	rotate_nowrite(&data->stack_b);
	write(1, "rr\n", 3);
}

void	rrr(t_data *data)
{
	reverse_rotate_nowrite(&data->stack_a);
	reverse_rotate_nowrite(&data->stack_b);
	write(1, "rrr\n", 4);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*new_last;

	if (stack && (*stack)->next)
	{
		new_last = *stack;
		*stack = (*stack)->next;
		new_last->next = NULL;
		new_last->prev = ft_lstlast(*stack);
		(*stack)->prev = NULL;
		ft_lstadd_back(stack, new_last);
	}
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*old_first;
	t_stack	*new_last;
	t_stack	*new_first;

	if (*stack && (*stack)->next)
	{
		old_first = *stack;
		new_first = ft_lstlast(*stack);
		new_last = new_first->prev;
		new_last->next = NULL;
		new_first->prev = NULL;
		new_first->next = old_first;
		old_first->prev = new_first;
		*stack = new_first;
	}
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
