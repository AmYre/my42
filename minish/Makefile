# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjozefzo <cjozefzo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/08 17:31:31 by amben-ha          #+#    #+#              #
#    Updated: 2024/02/16 19:08:45 by cjozefzo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	main.c\
				line_read.c\
				handle_signal.c\
				env.c\
				builtins/cd.c\
				builtins/pwd.c\
				builtins/echo.c\
				builtins/env.c\
				builtins/exit.c\
				builtins/unset.c\
				builtins/export.c\
				builtins/builtins.c\
				error_handler/erreur.c\
				error_handler/err_t_commands.c\
				error_handler/err_exec.c\
				error_handler/err_utils.c\
				execute/make_redirection.c\
				execute/struct_to_char.c\
				execute/check_cmd_path.c\
				execute/env_to_char.c\
				execute/execute.c\
				execute/saved_fd.c\
				execute/execute_command.c\
				execute/check_file_exist.c\
				expand/expand.c\
				expand/expand_str.c\
				expand/expand_utils.c\
				expand/ft_split_expand.c\
				expand/replace.c\
				expand/init_refill_t.c\
				help_function/ft_realloc.c\
				help_function/ft_atoi.c\
				help_function/ft_calloc.c\
				help_function/ft_isalnum.c\
				help_function/ft_isalpha.c\
				help_function/ft_lst_new_env.c\
				help_function/ft_lstsize.c\
				help_function/ft_lstsplit_path.c\
				help_function/ft_memcmp.c\
				help_function/ft_reallc_char.c\
				help_function/ft_strcat.c\
				help_function/ft_strcpy.c\
				help_function/ft_strdup.c\
				help_function/ft_strlen.c\
				help_function/is_num.c\
				help_function/is_space.c\
				help_function/ft_arrlen.c\
				help_function/ft_lst_env.c\
				help_function/ft_split.c\
				help_function/ft_strchr_sign.c\
				help_function/ft_strchr.c\
				help_function/ft_strjoin.c\
				help_function/ft_strncmp.c\
				help_function/ft_substr.c\
				help_function/ft_itoa.c\
				parsing/parse.c\
				parsing/check_quote.c\
				parsing/check_syntax.c\
				parsing/make_here_doc.c\
				parsing/make_here_doc_pipe.c\
				parsing/expand_here_doc.c\
				parsing/ft_trim/ft_trim_null.c\
				parsing/ft_trim/ft_trim.c\
				parsing/split_process/allocation.c\
				parsing/split_process/count.c\
				parsing/split_process/fill_redirection.c\
				parsing/split_process/ft_split_command.c\
				parsing/split_process/split_not_finished.c\
				parsing/split_word/ft_lstsplit.c\
				parsing/split_word/split_word.c\

OBJS		= ${SRCS:.c=.o}
NAME		= minishell
CC			= cc -g -Wall -Wextra -Werror

INCLUDES = -I.

all: ${NAME}

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -lreadline -lncurses

%.o: %.c minishell.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f ${OBJS}

fclean:		clean
	rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re