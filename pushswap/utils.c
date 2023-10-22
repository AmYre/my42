/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:31:33 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/07 23:50:11 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

t_stack	*get_smallest(t_stack *stack)
{
	t_stack	*current;
	t_stack	*smallest;
	long	compare;

	compare = LONG_MAX;
	current = stack;
	while (current)
	{
		if (current->value < compare)
		{
			compare = current->value;
			smallest = current;
		}
		current = current->next;
	}
	return (smallest);
}

t_stack	*get_biggest(t_stack *stack)
{
	t_stack	*current;
	t_stack	*biggest;
	long	compare;

	compare = LONG_MIN;
	current = stack;
	while (current)
	{
		if (current->value > compare)
		{
			compare = current->value;
			biggest = current;
		}
		current = current->next;
	}
	return (biggest);
}

void	rotate_nowrite(t_stack **stack)
{
	t_stack	*tmp;

	if (stack && (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = NULL;
		tmp->prev = ft_lstlast(*stack);
		(*stack)->prev = NULL;
		ft_lstadd_back(stack, tmp);
	}
}

void	reverse_rotate_nowrite(t_stack **stack)
{
	t_stack	*tmp_first;
	t_stack	*tmp_last;
	t_stack	*last;

	if (*stack && (*stack)->next)
	{
		tmp_first = *stack;
		tmp_last = ft_lstlast(*stack);
		last = tmp_last->prev;
		last->next = NULL;
		tmp_last->prev = NULL;
		tmp_last->next = tmp_first;
		tmp_first->prev = tmp_last;
		*stack = tmp_last;
	}
}
