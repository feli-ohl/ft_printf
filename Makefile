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
	@rm -f $(OBJ)
	@echo "Archivos objeto eliminados"

fclean: clean
	@rm -rf $(NAME)
	@rm -f tests.c runner_tests
	@echo "LIBRERÍA $(NAME) ELIMINADA"

re: fclean all

URL_TEST = https://raw.githubusercontent.com/feli-ohl/ft_printf/refs/heads/main/TESTS/tests.c

test: all
	@echo "Descargando tests desde GitHub..."
	@curl -s -O $(URL_TEST)
	@echo "Compilando..."
	@$(CC) $(CFLAGS) tests.c -L. -lftprintf -o runner_tests
	@echo "Archivo ejecutable runner_tests creado correctamente."
	@echo "Para borrar el archivo de tests y el ejecutable, ejecutar 'make fclean'."

.PHONY: all clean fclean re test