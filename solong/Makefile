# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/16 21:20:29 by amben-ha          #+#    #+#              #
#    Updated: 2023/09/19 00:19:13 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				moves.c\
				map.c\
				events.c\
				path.c\
				checks_items.c\
				checks_layout.c\
				utils.c\

OBJS		= ${SRCS:.c=.o}
NAME		= so_long
CC			= cc -g -Wall -Wextra -Werror

INCLUDES = -I. -I/usr/include -Ilibs/mlx -Ilibs/libft -Ilibs/printf -Ilibs/gnl

MLX_LIB = libs/mlx/libmlx_Linux.a
MLX_FLAGS = -Llibs/mlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIBFT = libs/libft/libft.a
PRINTF = libs/printf/printf.a
GNL = libs/gnl/gnl.a

all: ${NAME}

$(NAME): $(OBJS) $(MLX_LIB) $(LIBFT) $(PRINTF) $(GNL)
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(PRINTF) $(GNL)

$(MLX_LIB):
	make -C libs/mlx

$(LIBFT):
	make -C libs/libft

$(PRINTF):
	make -C libs/printf

$(GNL):
	make -C libs/gnl

%.o: %.c so_long.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}
	make -C libs/mlx clean
	make -C libs/libft clean
	make -C libs/printf clean
	make -C libs/gnl clean

fclean:		clean
	rm -f ${NAME}
	make -C libs/mlx clean
	make -C libs/libft fclean
	make -C libs/printf fclean
	make -C libs/gnl fclean

re:			fclean all

.PHONY:		all clean fclean re
