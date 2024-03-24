# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 01:50:23 by alsaeed           #+#    #+#              #
#    Updated: 2024/03/25 01:05:00 by mlumibao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

UNAME = $(shell uname)

CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibs/libft/ -lft -lm
INCLUDES = -Iincludes/ -Ilibs/libft/includes

ifeq ($(UNAME), Linux)
	CC = clang
	LDFLAGS += -Llibs/mlx_linux/ -lmlx_Linux -L/usr/lib -lXext -lX11 
	INCLUDES += -I/usr/include -Ilibs/mlx_linux/ -D__linux__
	MLX_DIR = libs/mlx_linux/
else ifeq ($(UNAME), Darwin)
	CC = cc
	LDFLAGS += -Llibs/mlx_macos/ -lmlx -framework OpenGL -framework AppKit -L/usr/lib
	INCLUDES += -Ilibs/mlx_macos/
	MLX_DIR = libs/mlx_macos/
endif

SRCD =	check.c \
		free.c \
		init_game.c \
		init_text.c \
		init_utils.c \
		verify.c \
		verify_utils.c \
		testing_utils.c \
		check_elements.c \
		scan_utils.c \
		map_utils.c \
		map_edit.c \
		get_file.c \
		element_utils.c \
		check_map_utils.c \
		final_parse.c

SRCX =	init.c \
		rect_map.c \
		raycast.c \
		keymap.c \
		wasd_move.c \
		wall_collision.c \
		draw_wall.c \
		draw_utils.c \
		close_game.c

OBJD_DIR = src/parsing/objs
OBJD = $(SRCD:%.c=$(OBJD_DIR)/%.o)
OBJX_DIR = src/execution/objs
OBJX = $(SRCX:%.c=$(OBJX_DIR)/%.o)

LIBFT_DIR = libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
MINILIBX = $(MLX_DIR)libmlx.a

all: $(NAME)

$(OBJD_DIR)%.o: src/parsing%.c
	@mkdir -p $(OBJD_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
$(OBJX_DIR)%.o: src/execution%.c
	@mkdir -p $(OBJX_DIR)
	@$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@
	
$(NAME): $(LIBFT) $(MINILIBX) $(OBJD) $(OBJX) main.c
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJD) $(OBJX) main.c -o $(NAME) $(LDFLAGS)
	@echo "cub3D Compiled : \033[1;32mOK\033[0m"

$(LIBFT):
	@make -sC $(LIBFT_DIR)

$(MINILIBX):
	@make -sC $(MLX_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		cp $(MLX_DIR)libmlx.a ./ ; \
	fi
	@echo "minilibx Compiled : \033[1;32mOK\033[0m"

norm:
	norminette

clean:
	@make clean -sC $(LIBFT_DIR)
	@make clean -sC $(MLX_DIR)
	@if [ -e $(OBJD_DIR) ]; then \
		rm -rf $(OBJD_DIR); \
		echo "cub3D-parsing Clean: \033[32mOK\033[0m"; \
	fi
	@if [ -e $(OBJX_DIR) ]; then \
		rm -rf $(OBJX_DIR); \
		echo "cub3D-execution Clean: \033[32mOK\033[0m"; \
	fi
 
fclean: clean
	@make fclean -sC $(LIBFT_DIR)
	@if [ $(UNAME) = Darwin ]; then \
		rm -rf ./libmlx.a ; \
	fi
	@if [ -e $(NAME) ]; then \
		rm -f $(NAME); \
		echo "cub3D Full-Clean: \033[32mOK\033[0m"; \
	fi

re: fclean all

.PHONY: all clean fclean re