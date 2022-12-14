# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npinheir <npinheir@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 14:10:26 by npinheir          #+#    #+#              #
#    Updated: 2021/11/05 11:08:21 by npinheir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the program
NAME = fdf

# Compiling flags
FLAGS = -Wall -Wextra -Werror -g

# Folders
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./include/
LIBFT_DIR = ./libft/
MINLBX_DIR = ./minilibx/

# Source files and object files
SRC_FILES = main.c errors.c utils.c create_map.c mlx.c math.c hook.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC	:= $(wildcard $(SRC_DIR)*.c)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)
MINLBX	= $(addprefix $(MINLBX_DIR), libmlx.a)

# Libft and Minilibx linkers
LNK  = -L $(LIBFT_DIR) -lft -L $(MINLBX_DIR) \
			-lmlx -framework OpenGL -framework AppKit

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
NONE = \033[0m

# all rule
all: obj $(LIBFT) $(MINLBX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)
	@echo "\t$(GREEN)✔ Object folder created in Fdf !$(NONE)"
	
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(FLAGS) -I $(MINLBX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<
	
$(LIBFT):
	@make -C $(LIBFT_DIR)
	
$(MINLBX):
	@make -C $(MINLBX_DIR)

# Compiling
$(NAME): $(OBJ)
	@gcc $(OBJ) $(LNK) -lm -o $(NAME)
	@echo "\t$(GREEN)✔ FdF ready to run !$(NONE)"

# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MINLBX_DIR) clean
	@echo "\t$(GREEN)✔ All objects removed !$(NONE)"

# fclean rule
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\t$(GREEN)✔ Project fully cleaned !$(NONE)"

# re rule
re: fclean all

# phony
.PHONY: all clean fclean re
