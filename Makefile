NAME 		= libftprintf.a
CC 			= cc
CFLAGS		= -Wall -Werror -Wextra

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRC			= ft_printf.c \
              ft_print_char.c \
			  ft_print_string.c \
			  ft_print_pointer.c \
			  ft_print_integer.c \
			  ft_print_unsigned.c \
			  ft_print_hex.c

OBJ 		= $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@echo "LIBRERÍA $(NAME) CREADA"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJ)
	@echo "Archivos objeto eliminados"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME)
	@echo "LIBRERÍA $(NAME) ELIMINADA"

re: fclean all

.PHONY: all clean fclean re