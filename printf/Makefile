# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/22 23:05:25 by amben-ha          #+#    #+#              #
#    Updated: 2023/06/26 21:18:48 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_printf.c\
				ft_printnbr.c\
				ft_printunbr.c\
				ft_printhexa.c\
				ft_printchar.c\
				ft_printstr.c\
				ft_printp.c\

OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= cc -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) -I. -c $< -o $@

bonus: ${OBJS_BONUS} ft_printf.h
	ar rcs ${NAME} ${OBJS_BONUS}

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME} ${OBJS_BONUS} a.out

re:			fclean all

.PHONY:		all clean fclean re
