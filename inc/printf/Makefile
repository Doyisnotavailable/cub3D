NAME = libftprintf.a
LIBFT_DIR = ./../libft
LIBFT_NAME = libft.a
SRCS = ft_printf.c print_char.c print_hex.c print_int.c print_ptr.c print_str.c print_uns.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc

all: $(NAME)	

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT_NAME) .
	mv $(LIBFT_NAME) $(NAME)
	ar -r $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJS)

fclean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re