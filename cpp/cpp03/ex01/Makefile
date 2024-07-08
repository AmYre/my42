# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/05 20:51:55 by amben-ha          #+#    #+#              #
#    Updated: 2024/05/08 23:16:00 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \


OBJS_DIR = ./objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98
NAME = scavtrap

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

.PHONY: all clean fclean