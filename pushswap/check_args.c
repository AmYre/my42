/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:11:13 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/08 16:11:23 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max(int argc, t_data *data)
{
	int	i;
	int	len;

	i = 1;
	if (argc == 2)
		len = data->args_len + 1;
	else
		len = argc;
	while (i < len)
	{
		if (ft_strlen(data->args[i]) > 12)
			return (1);
		if (ft_atoi(data->args[i]) > INT_MAX
			|| ft_atoi(data->args[i]) < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}

int	check_doubles(int argc, t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	if (argc == 2)
		len = data->args_len;
	else
		len = argc - 1;
	while (i < len)
	{
		j = i + 1;
		while (j < len + 1)
		{
			if (ft_atoi(data->args[i]) == ft_atoi(data->args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_chars(int argc, t_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	if (argc == 2)
		len = data->args_len;
	else
		len = argc - 1;
	while (i < len)
	{
		j = 0;
		if (data->args[i][j] == '-')
			j++;
		while (data->args[i][j])
		{
			if (data->args[i][j] < '0' || data->args[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_sorted(t_data *data)
{
	t_stack	*current;

	current = data->stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

void	check_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
				data->args_len++;
			i++;
		}
		data->args_len++;
	}
	else
		data->args_len = argc - 1;
	if (check_max(argc, data))
		return (ft_printf("Error\n"), free_stack(data, argc), exit(0));
	else if (check_doubles(argc, data))
		return (ft_printf("Error\n"), free_stack(data, argc), exit(0));
	else if (check_chars(argc, data))
		return (ft_printf("Error\n"), free_stack(data, argc), exit(0));
	else
		return ;
}
