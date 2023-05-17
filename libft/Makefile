# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 17:58:27 by amben-ha          #+#    #+#              #
#    Updated: 2023/05/17 15:57:39 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \

SRCS_BONUS	=	ft_lstadd_back_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstmap_bonus.c \
				ft_lstnew_bonus.c \
				ft_lstsize_bonus.c

OBJS		= ${SRCS:.c=.o}
OBJS_BONUS	= ${SRCS_BONUS:.c=.o}
NAME		= libft.a
CC			= gcc -Wall -Wextra -Werror

all: ${NAME}

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#r means that if the library already exists, replace the old files within the library with your new files.\
#c means create the library if it did not exist.\
#s can be seen to mean 'sort' (create a sorted index of) the library, so that it will be indexed and faster to access the functions in the library.\
Therefore, rcs can be seen to mean replace, create, sort.\

#We have to include libft.h as a dependency. Without it f you were to make a change to libft.h, "make" would not recompile the .c files, even though they needed to be.\

%.o: %.c libft.h
	$(CC) -I. -c $< -o $@

#so:\
#	gcc -nostartfiles -fPIC -Wall -Wextra -Werror $(SRCS) $(SRCS_BONUS)\
#	gcc -nostartfiles -shared -o libft.so $(OBJS) ${OBJS_BONUS}\

bonus: ${OBJS_BONUS} libft.h
	ar rcs ${NAME} ${OBJS_BONUS}

#the -c flag says to generate the object file independently.\
#the -o $@ says to put the output of the compilation in the file named on the left side of the semi:colon\
#the $< is the first item in the dependencies list \
#The -I. is included so that gcc will look in the current directory (.) for the include file libft.h\

#test : all\
#	$(CC) test.c -L. -lft -lbsd -o test\

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME} ${OBJS_BONUS}

re:			fclean all

.PHONY:		all clean fclean re
#The .PHONY rule keeps "make" from doing something with a file named all, clean, fclean or re.\
