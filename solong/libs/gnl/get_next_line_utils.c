/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 21:14:09 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/19 02:23:35 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list	*get_last(t_list *stash)
{
	t_list	*current;

	current = stash;
	while (current->next)
		current = current->next;
	return (current);
}

int	breakline_checker(t_list *stash)
{
	int		i;
	t_list	*current;

	i = 0;
	if (!stash)
		return (0);
	current = get_last(stash);
	while (current->content[i])
	{
		if (current->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	mallocate_line(t_list *stash, char **line)
{
	int	i;
	int	line_length;

	line_length = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				line_length++;
				break ;
			}
			line_length++;
			i++;
		}
		stash = stash->next;
	}
	*line = malloc(sizeof(char) * line_length + 1);
}

void	free_stash(t_list *stash)
{
	t_list	*current;
	t_list	*next;

	current = stash;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
	stash = NULL;
}
