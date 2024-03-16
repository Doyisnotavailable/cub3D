NAME = cub3D

SRC_DIR = ./src
SRC =	main.c check.c free.c init_game.c init_utils.c verify.c verify_utils.c testing_utils.c check_elements.c scan_utils.c map_utils.c map_edit.c get_file.c element_utils.c check_map_utils.c init.c rect_map.c final_parse.c raycast.c keymap.c util.c wasd_move.c wall_collision.c draw_wall.c draw_utils.c

START = make -C ./inc/printf
PRINTF = -L./inc/printf -lftprintf
CC = cc
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
$(shell mkdir -p $(OBJ_DIR))
MLX = make -C mlx


all: $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(START)
	$(MLX)
	$(CC) -g $(PRINTF) $(OBJ) -fsanitize=address -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	$(RM) $(OBJ)
	make -C inc/printf clean
	make -C mlx clean

fclean: clean
	$(RM) $(NAME) $(OBJ)
	make -C inc/printf fclean

re: fclean all

.PHONY: clean fclean all re
