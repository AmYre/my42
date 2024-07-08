# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/26 21:44:29 by amben-ha          #+#    #+#              #
#    Updated: 2024/05/29 20:14:18 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	main.cpp \
		Serializer.cpp

OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
NAME = serialize

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME) $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean