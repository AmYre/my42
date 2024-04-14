# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amben-ha <amben-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 15:42:44 by ryounssi          #+#    #+#              #
#    Updated: 2024/04/15 00:35:00 by amben-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# ***************************** PROJECT'S NAME ******************************* #
# **************************************************************************** #

NAME					=	cub3D

# **************************************************************************** #
# *************************** FLAGS & COMMANDS ******************************* #
# **************************************************************************** #

CC						=	cc
FLAGS					=	-Wall -Wextra -Werror -g3 -MMD
RM						=	rm -rf

# **************************************************************************** #
# ********************************* HEADERS ********************************** #
# **************************************************************************** #

HEADER_FILES	= cub3D
HEADERS_PATH 	= includes/
HEADERS			= $(addsuffix .h, $(addprefix $(HEADERS_PATH), $(HEADER_FILES)))
HEADERS_INC		= $(addprefix -I, $(HEADERS_PATH) $(LIB_HEADER_PATH) $(MLIB_HEADER_PATH))

# **************************************************************************** #
# ********************************** LIBFT *********************************** #
# **************************************************************************** #

LIB_NAME 	= ft
LIB_PATH	= libft/
LIB			= -L$(LIB_PATH) -l$(LIB_NAME) -lreadline
LIB_HEADER_PATH = $(LIB_PATH)includes/

# **************************************************************************** #
# ********************************* MINILIBX ********************************* #
# **************************************************************************** #

MLIB_NAME 	= mlx
MLIB_PATH	= minilibx-linux/
MLIB		= -L$(MLIB_PATH) -l$(MLIB_NAME) -lreadline
MLIB_HEADER_PATH = $(MLIB_PATH)minilibx-linux/
MLX_FLAGS	= -L./mlx -lmlx -lm -lX11 -lXext

# **************************************************************************** #
# ********************************* SOURCES ********************************** #
# **************************************************************************** #

# List of all .c source files
ROOT_FILE = main
INIT_FILES = init_base init_img init_ray init_minimap
INIT_FOLDER = init_game/
RENDER_FILES = raycasting_base raycasting_display
RENDER_FOLDER = raycasting/
MOVE_FILES = moves_keys_img moves_player
MOVE_FOLDER = moves/
PARSING_FOLDER = parsing/
PARSING_FILES = parsing_basics parsing_file parsing_map parsing_rgb parsing_utils parsing_spaces
UTILS_FILES = exit_clean
UTILS_FOLDER = clean_utils/


SRCS_PATH = srcs/
SRCS_NAMES 	= $(addsuffix .c,$(ROOT_FILE) \
				$(addprefix $(MOVE_FOLDER), $(MOVE_FILES)) \
				$(addprefix $(INIT_FOLDER), $(INIT_FILES)) \
				$(addprefix $(RENDER_FOLDER), $(RENDER_FILES)) \
				$(addprefix $(UTILS_FOLDER), $(UTILS_FILES)) \
				$(addprefix $(PARSING_FOLDER), $(PARSING_FILES)))

# **************************************************************************** #
# ********************************** OBJECTS ********************************* #
# **************************************************************************** #

# All .o files go to objs directory
OBJS_NAMES	= $(SRCS_NAMES:.c=.o)
OBJS_FOLDERS = $(addprefix $(OBJS_PATH), $(PARSING_FOLDER) $(INIT_FOLDER) \
			   $(RENDER_FOLDER) $(MOVE_FOLDER) $(PARSING_FOLDER) $(UTILS_FOLDER) $(PARSING_FOLDER))
OBJS_PATH 	= objs/
OBJS		= $(addprefix $(OBJS_PATH), $(OBJS_NAMES))

# Gcc/Clang will create these .d files containing dependencies
DEPS		= $(addprefix $(OBJS_PATH), $(SRCS_NAMES:.c=.d))

# **************************************************************************** #
# ********************************** RULES *********************************** #
# **************************************************************************** #

#all:	header $(NAME)
#	@echo "\n$(GREEN)[ ✔ ] cub3D$(WHITE)"
#	@echo "\n▶ TO LAUNCH:\t./cub3D\n"

all:	$(NAME)
	@echo "\n$(GREEN)[ ✔ ] cub3D$(WHITE)"
	@echo "\n▶ TO LAUNCH:\t./cub3D\n"
	@echo "$(GREEN)$(BOLD)$(QUICK_BLINK)$$HEADER_PROJECT"

# Actual target of the binary - depends on all .o files
$(NAME): lib mlib $(HEADERS) $(OBJS)
# Link all the object files
	@$(CC) $(FLAGS) $(MLX_FLAGS) $(HEADERS_INC) $(OBJS) $(LIB) $(MLIB) -lm -o $(NAME) -lmlx -lm -lX11 -lXext
# Build target for every single object file
# The potential dependency on header files is covered
# by calling `-include $(DEPS)`
$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
# Create objs directory
	@mkdir -p $(OBJS_FOLDERS)
  # The -MMD flags additionaly creates a .d file with
  # the same name as the .o file.
	@$(CC) $(FLAGS) $(HEADERS_INC) -MMD -MP -o $@ -c $<
	@printf "$(YELLOW)$(STRIKED_SWAP). . . CUB3D IS CHARGING . . . $(GREY)%-33.33s\r$(DEF_COLOR)" $@

lib:
	@$(MAKE) --no-print-directory -s -C $(LIB_PATH)
	@echo "\n$(GREEN)$(BOLD)[ ✔ ] LIBFT IS HERE$(DEF_COLOR)"

mlib:
	@$(MAKE) --no-print-directory -s -C $(MLIB_PATH)
	@echo "\n$(GREEN)$(BOLD)[ ✔ ] MLIB APPEARED$(DEF_COLOR)"

clean:
	@echo "$(YELLOW)$(STRIKED_SWAP)\n. . . CLEANING IN PROGRESS . . .\n$(DEF_COLOR)"
	@$(MAKE) clean --no-print-directory -C $(LIB_PATH)
	@$(MAKE) clean --no-print-directory -C $(MLIB_PATH)
	@$(RM) -rd $(OBJS_PATH)
	@echo "$(GREEN)[ ✔ ] OBJECTS CLEANED$(DEF_COLOR)"

fclean:	clean
	@echo "$(YELLOW)$(STRIKED_SWAP)\n. . . JUST TO BE SURE . . .\n$(DEF_COLOR)"
	@$(MAKE) --no-print-directory fclean -C $(LIB_PATH)
	@$(MAKE) --no-print-directory clean -C $(MLIB_PATH)
	@$(RM) $(NAME)
	@echo "$(GREEN)[ ✔ ] ALL CLEANED$(DEF_COLOR)"

re:	fclean all

# Include all .d files
-include $(DEPS)

.PHONY:	all clean fclean re header norme check lib

# **************************************************************************** #
# ********************************* CUSTOM *********************************** #
# **************************************************************************** #

define HEADER_PROJECT


 .----------------.  .----------------.  .----------------.  .----------------.  .----------------.
| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |
| |     ______   | || | _____  _____ | || |   ______     | || |    ______    | || |  ________    | |
| |   .' ___  |  | || ||_   _||_   _|| || |  |_   _ \    | || |   / ____ `.  | || | |_   ___ `.  | |
| |  / .'   \_|  | || |  | |    | |  | || |    | |_) |   | || |   `'  __) |  | || |   | |   `. \ | |
| |  | |         | || |  | '    ' |  | || |    |  __'.   | || |   _  |__ '.  | || |   | |    | | | |
| |  \ `.___.'\  | || |   \ `--' /   | || |   _| |__) |  | || |  | \____) |  | || |  _| |___.' / | |
| |   `._____.'  | || |    `.__.'    | || |  |_______/   | || |   \______.'  | || | |________.'  | |
| |              | || |              | || |              | || |              | || |              | |
| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |
 '----------------'  '----------------'  '----------------'  '----------------'  '----------------'


endef
export HEADER_PROJECT

#header:
#		clear
#		@echo "$$HEADER_PROJECT"

norme:
	norminette $(HEADERS) $(SRCS_PATH) $(LIB_PATH)

#Colors
DEF_COLOR = \033[0;39m
GREY = \033[0;90m
RED = \033[0;91m
GREEN = \033[1;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[1;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

BOLD = \033[1m
QUICK_BLINK = \033[6m
ALT_FONT01 = \033[11m
STRIKED_SWAP = \033[7m
