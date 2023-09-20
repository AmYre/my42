# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 23:05:25 by amben-ha          #+#    #+#              #
#    Updated: 2023/09/19 01:10:08 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	get_next_line.c\
				get_next_line_utils.c\

OBJS		= ${SRCS:.c=.o}
NAME		= gnl.a
CC			= cc -g -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c get_next_line.h
	$(CC) -I. -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME} ${OBJS} a.out

re:			fclean all

.PHONY:		all clean fclean re
