NAME = cub3D

SRC_DIR = ./src
SRC = main.c check.c free.c init_game.c init_utils.c verify.c verify_utils.c check_elements.c

START = make -C ./inc/printf
PRINTF = -L./inc/printf -lftprintf
CC = cc -I./inc/printf
OBJ_DIR = ./obj
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
$(shell mkdir -p $(OBJ_DIR))
CFLAGS = -Wall -Wextra -Werror

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(START)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(PRINTF)

clean:
	$(RM) $(OBJ)
	make -C inc/printf clean

fclean:
	$(RM) $(NAME) $(OBJ)
	make -C inc/printf fclean

re: fclean all

.PHONY: clean fclean all re
