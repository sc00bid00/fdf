# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsordo <lsordo@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 07:43:52 by lsordo            #+#    #+#              #
#    Updated: 2023/01/20 13:55:18 by lsordo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ofast
FFLAGS = -framework Cocoa -framework OpenGL -framework IOKit
SRC_DIR = ./src/
OBJ_DIR = ./obj/
LIBMLX42_DIR = ./lib/MLX42/
LIBGLFW = ./lib/glfw/glfw-3.3.8.bin.MACOS/lib-x86_64/libglfw3.a
LIBMLX42 = $(LIBMLX42_DIR)libmlx42.a
MAP_DIR = ./test_maps/
INC_DIR = -I ./include -I ./lib/libft -I ./lib/get_next_line/include\
			-I ./lib/glfw/glfw-3.3.8.bin.MACOS/include/GLFW -I ./lib/MLX42/include/MLX42
LIBFT = ./lib/libft/libft.a
LIBGNL = ./lib/get_next_line/libgnl.a


SRC =	utils_data.c\
		utils_draw.c\
		utils_graph.c\
		utils_init.c\
		utils_matrix.c\
		utils_mem.c\
		utils_parse.c\
		utils_transf.c\
		utils_hook.c\
		utils_cleanup.c\
		utils_calc.c\
		utils_ctrl.c\
		utils_project.c\
		utils_extra.c\
		fdf.c

OBJ = $(SRC:%.c=$(OBJ_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(LIBFT) $(LIBGNL) $(LIBGLFW) $(LIBMLX42) $(OBJ) $(MAP_DIR)
	@$(CC) $(OBJ) $(LIBFT) $(LIBGNL) $(LIBGLFW) $(LIBMLX42) -o $(NAME) $(FFLAGS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) -c $(CFLAGS) $(INC_DIR) $^ -o $@

$(OBJ_DIR):
	@mkdir -p ./obj

$(LIBFT):
	@$(MAKE) -C ./lib/libft
$(LIBGNL):
	@$(MAKE) -C ./lib/get_next_line
$(LIBGLFW):
	@mkdir -p ./lib/glfw
	@curl -fsSL https://github.com/glfw/glfw/releases/download/3.3.8/glfw-3.3.8.bin.MACOS.zip | tar -xz
	@rm -rf __MACOSX
	@mv ./glfw-3.3.8.bin.MACOS ./lib/glfw
$(LIBMLX42): $(LIBMLX42_DIR)
	@$(MAKE) -C ./lib/MLX42
$(LIBMLX42_DIR):
	@mkdir -p ./lib/MLX42
	@git clone https://github.com/codam-coding-college/MLX42.git ./lib/MLX42
$(MAP_DIR):
	@curl -fsSL https://projects.intra.42.fr/uploads/document/document/13499/maps.zip | tar -xz
	@rm -rf __MACOSX
clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C ./lib/libft
	@make clean -C ./lib/get_next_line
	@make clean -C ./lib/MLX42

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./lib/libft
	@make fclean -C ./lib/get_next_line
	@make fclean -C	./lib/MLX42

re: fclean all

.PHONY: all clean fclean re

