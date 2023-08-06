/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 01:34:43 by amben-ha          #+#    #+#             */
/*   Updated: 2023/08/07 00:50:55 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_stash(t_list **stash)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;

	i = 0;
	j = 0;
	clean_node = malloc(sizeof(t_list));
	if (!clean_node)
		return ;
	clean_node->next = NULL;
	last_node = get_last(*stash);
	while (last_node->content[i] && last_node->content[i] != '\n')
		i++;
	if (last_node->content && last_node->content[i] == '\n')
		i++;
	clean_node->content = malloc(sizeof(char) * (ft_strlen(last_node->content)
				- i + 1));
	if (!clean_node->content)
		return ;
	while (last_node->content[i])
		clean_node->content[j++] = last_node->content[i++];
	clean_node->content[j] = '\0';
	free_stash(*stash);
	*stash = clean_node;
}

void	create_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	mallocate_line(stash, line);
	if (!*line)
		return ;
	j = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			if (stash->content[i] == '\n')
			{
				(*line)[j++] = '\n';
				break ;
			}
			(*line)[j++] = stash->content[i++];
		}
		stash = stash->next;
	}
	(*line)[j] = '\0';
}

void	add_to_stash(t_list **stash, char *buf, int bytes_read)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->content = malloc(sizeof(char) * (bytes_read + 1));
	if (new_node->content == NULL)
		return ;
	i = 0;
	while (buf[i] && i < bytes_read)
	{
		new_node->content[i] = buf[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*stash == NULL)
	{
		*stash = new_node;
		return ;
	}
	last = get_last(*stash);
	last->next = new_node;
}

void	read_and_stash(t_list **stash, int fd)
{
	char	*buf;
	int		bytes_read;

	bytes_read = 1;
	while (!breakline_checker(*stash) && bytes_read)
	{
		buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return ;
		bytes_read = (int)read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		add_to_stash(stash, buf, bytes_read);
		free(buf);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stash;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	line = NULL;
	read_and_stash(&stash, fd);
	if (!stash)
		return (NULL);
	create_line(stash, &line);
	clean_stash(&stash);
	if (!line[0])
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
