/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:53:48 by amben-ha          #+#    #+#             */
/*   Updated: 2023/10/07 23:50:27 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libs/libft/libft.h"
# include "./libs/printf/ft_printf.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				is_cheapest;
	int				upper_half;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_data
{
	int				current_size_a;
	int				current_size_b;
	long			best_match_index;
	int				args_len;
	char			**args;
	int				size;
	t_stack			*cheapest;
	t_stack			*target_five;
	t_stack			*stack_a;
	t_stack			*stack_b;
}					t_data;

void				push_swap(t_data *data);
void				init_stack(int argc, char **argv, t_data *data);
void				init_sort(t_data *data);
void				sort(t_data *data);
void				small_sort(t_data *data);
void				tiny_sort(t_data *data);

void				set_indexes(t_stack *stack);
void				get_targets(t_data *data);
void				set_costs(t_data *data);
void				get_cheapest(t_data *data);

void				complete_five(t_data *data, int middle);
void				handle_five(t_data *data, int middle);
void				target_five(t_data *data);
t_stack				*get_smallest(t_stack *stack);
t_stack				*get_biggest(t_stack *stack);

void				push_a(t_data *data);
void				push_b(t_data *data);
void				swap_a(t_data *data);
void				swap_b(t_data *data);

void				rr(t_data *data);
void				rrr(t_data *data);
void				rotate(t_stack **stack, char c);
void				rotate_nowrite(t_stack **stack);
void				rotate_both(t_data *data);
void				reverse_rotate(t_stack **stack, char c);
void				reverse_rotate_nowrite(t_stack **stack);
void				reverse_rotate_both(t_data *data);
void				complete_rotations(t_data *data);

void				ft_lstadd_back(t_stack **lst, t_stack *new);
int					ft_lstsize(t_stack *lst);
t_stack				*ft_lstlast(t_stack *lst);
t_stack				*ft_lstnew(int value);

void				check_args(int argc, char **argv, t_data *data);
int					check_max(int argc, t_data *data);
int					check_doubles(int argc, t_data *data);
int					check_chars(int argc, t_data *data);
int					check_sorted(t_data *data);
void				free_split(char **split);
void				free_stack(t_data *data, int argc);
#endif