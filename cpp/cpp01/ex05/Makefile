# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 02:11:45 by amben-ha          #+#    #+#              #
#    Updated: 2024/04/26 00:23:40 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp \
		Harl.cpp \

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = harl

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

re: fclean all

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME) $(OBJS_DIR)

.PHONY: all clean fclean