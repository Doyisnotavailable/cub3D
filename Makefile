NAME = cub3D

SRC_DIR = ./src
SRC =	main.c check.c free.c init_game.c init_utils.c verify.c verify_utils.c testing_utils.c check_elements.c scan_utils.c map_utils.c map_edit.c get_file.c element_utils.c check_map_utils.c \
		mlx_functions.c win_manipulation.c init.c rect_map.c final_parse.c raycast.c keymap.c\

CC = cc
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
$(shell mkdir -p $(OBJ_DIR))
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -g
MLX = cd mlx && make
LIB = cd libft && make

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB)
	$(MLX)
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(MAKE) clean -C mlx
	cd libft && make clean

fclean: clean
		rm -f $(NAME)
		cd libft && make fclean

re: fclean all

.PHONY: clean fclean all re
