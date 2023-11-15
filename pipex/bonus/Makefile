# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 17:31:31 by amben-ha          #+#    #+#              #
#    Updated: 2023/11/12 00:58:50 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main_bonus.c\
				exec_bonus.c\
				redirects_bonus.c\
				heredoc_bonus.c\

OBJS		= ${SRCS:.c=.o}
NAME		= pipex
CC			= cc -Wall -Wextra -Werror

INCLUDES = -I. -I../libs/libft -I../libs/printf

LIBFT = ../libs/libft/libft.a
PRINTF = ../libs/printf/printf.a

all: ${NAME}

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C ../libs/libft

$(PRINTF):
	make -C ../libs/printf

%.o: %.c pipex_bonus.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C ../libs/libft clean
	make -C ../libs/printf clean

fclean:		clean
	rm -f ${NAME}
	make -C ../libs/libft fclean
	make -C ../libs/printf fclean

re:			fclean all

.PHONY:		all clean fclean re