# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 17:31:31 by amben-ha          #+#    #+#              #
#    Updated: 2023/11/12 22:09:14 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				exec.c\
				redirects.c\

OBJS		= ${SRCS:.c=.o}
NAME		= pipex
CC			= cc -Wall -Wextra -Werror

INCLUDES = -I. -Ilibs/libft -Ilibs/printf

LIBFT = libs/libft/libft.a
PRINTF = libs/printf/printf.a

all: ${NAME}

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C libs/libft

$(PRINTF):
	make -C libs/printf

%.o: %.c pipex.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C libs/libft clean
	make -C libs/printf clean
	make -C bonus clean

fclean:		clean
	rm -f ${NAME}
	make -C libs/libft fclean
	make -C libs/printf fclean
	make -C bonus fclean

bonus:
	make -C bonus

re:			fclean all

.PHONY:		all clean fclean re bonus