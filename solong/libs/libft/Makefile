# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 17:58:27 by amben-ha          #+#    #+#              #
#    Updated: 2023/09/14 23:19:20 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_strlen.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_itoa.c \


OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= cc -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) -I. -c $< -o $@

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME} ${OBJS_BONUS}

re:			fclean all

.PHONY:		all clean fclean re
