# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/25 02:55:49 by amben-ha          #+#    #+#              #
#    Updated: 2024/03/11 02:16:32 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				utils.c\
				routine.c\
				parsing.c\
				monitoring.c\

OBJS		= ${SRCS:.c=.o}
NAME		= philo
CC			= cc -Wall -Wextra -Werror #-pthread -fsanitize=address -g -g3

INCLUDES = -I.

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

%.o: %.c philo.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re