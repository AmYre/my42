/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 22:36:38 by amben-ha          #+#    #+#             */
/*   Updated: 2023/09/17 21:15:36 by amben-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct list
{
	char		*content;
	struct list	*next;
}				t_list;

char			*get_next_line(int fd);
void			read_and_stash(t_list **stash, int fd);
void			add_to_stash(t_list **stash, char *buf, int bytes_read);
void			create_line(t_list *stash, char **line);
void			clean_stash(t_list **stash);
int				breakline_checker(t_list *stash);
void			mallocate_line(t_list *stash, char **line);
int				gnl_strlen(char *s);
t_list			*get_last(t_list *stash);
void			free_stash(t_list *stash);

#endif