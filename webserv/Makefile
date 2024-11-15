# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/15 23:26:07 by amben-ha          #+#    #+#              #
#    Updated: 2024/11/11 22:02:54 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	main.cpp \
		init_servers.cpp \
		handlers.cpp \
		parsers.cpp \
		methods.cpp \
		utils.cpp \
		cgis.cpp \

SRC = $(addprefix src/, $(SRCS))
OBJS_DIR = src/objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

CC = c++
CFLAGS = -Wall -Wextra -Werror -g -std=c++98 -I .
NAME = webserv

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

-include $(DEPS)

$(OBJS_DIR)/%.o: src/%.cpp
	$(CC) $(CFLAGS) -MMD -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -rf $(NAME) $(OBJS_DIR)

re: fclean all

.PHONY: all clean fclean

# export HOMEBREW_PREFIX="/mnt/nfs/homes/amben-ha/homebrew"
# export HOMEBREW_CELLAR="/mnt/nfs/homes/amben-ha/homebrew/Cellar"
# export HOMEBREW_REPOSITORY="/mnt/nfs/homes/amben-ha/homebrew"
# export PATH="$HOMEBREW_PREFIX/bin:$HOMEBREW_PREFIX/sbin:$PATH"

# netstat -an | grep :5000 chercher ESTABLISHED ou CLOSE_WAIT pour des connections suspendues

# htop pour voir les processus en live

# curl --resolve layura.com:5000:127.0.25.1 http://layura.com:5000/