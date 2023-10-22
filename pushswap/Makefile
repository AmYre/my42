# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 18:55:22 by amben-ha          #+#    #+#              #
#    Updated: 2023/10/07 23:53:00 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				init_sort.c \
				sort_five.c \
				commands.c \
				actions.c \
				rotate_actions.c \
				utils.c \
				check_args.c \
				ft_lstnew.c \
				ft_lstadd_back.c \
				ft_lstlast.c \
				ft_lstsize.c \

OBJS		= ${SRCS:.c=.o}
NAME		= push_swap
CC			= cc -g -Wall -Wextra -Werror

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


%.o: %.c push_swap.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C libs/libft clean
	make -C libs/printf clean

fclean:		clean
	rm -f ${NAME}
	make -C libs/libft fclean
	make -C libs/printf fclean

re:			fclean all

.PHONY:		all clean fclean re
