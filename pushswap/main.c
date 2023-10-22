/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:54:27 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/07 23:50:19 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_data *data, int argc)
{
	t_stack	*current_a;
	t_stack	*current_b;
	t_stack	*next;

	if (argc == 2)
		free_split(data->args);
	current_a = data->stack_a;
	current_b = data->stack_b;
	while (current_a)
	{
		next = current_a->next;
		free(current_a);
		current_a = next;
	}
	data->stack_a = NULL;
	while (current_b)
	{
		next = current_b->next;
		free(current_b);
		current_b = next;
	}
	data->stack_b = NULL;
}

void	sort(t_data *data)
{
	if (data->cheapest->upper_half && data->cheapest->target->upper_half)
		rotate_both(data);
	else if (!(data->cheapest->upper_half)
		&& !(data->cheapest->target->upper_half))
		reverse_rotate_both(data);
	complete_rotations(data);
	push_b(data);
}

void	init_sort(t_data *data)
{
	set_indexes(data->stack_a);
	set_indexes(data->stack_b);
	get_targets(data);
	set_costs(data);
	get_cheapest(data);
}

void	push_swap(t_data *data)
{
	t_stack	*smallest_a;

	push_b(data);
	push_b(data);
	while (data->stack_a)
	{
		init_sort(data);
		sort(data);
	}
	while (data->stack_b)
		push_a(data);
	set_indexes(data->stack_a);
	smallest_a = get_smallest(data->stack_a);
	if (smallest_a->upper_half)
		while (data->stack_a != smallest_a)
			rotate(&data->stack_a, 'a');
	else
		while (data->stack_a != smallest_a)
			reverse_rotate(&data->stack_a, 'a');
}

int	main(int argc, char **argv)
{
	static t_data	data = {0};
	int				i;

	i = 0;
	if (argc <= 1)
		return (1);
	if (argc == 2)
		data.args = ft_split(argv[1], ' ');
	else
		data.args = argv;
	check_args(argc, argv, &data);
	while (data.args[++i])
		ft_lstadd_back(&(data.stack_a), ft_lstnew(ft_atoi(data.args[i])));
	if (check_sorted(&data))
		return (free_stack(&data, argc), 0);
	data.size = ft_lstsize(data.stack_a);
	data.current_size_a = data.size;
	if (data.size <= 3)
		tiny_sort(&data);
	else if (data.size <= 5)
		small_sort(&data);
	else
		push_swap(&data);
	free_stack(&data, argc);
	return (0);
}
