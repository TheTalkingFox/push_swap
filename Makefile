NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c stack.c operations.c input.c helpers_input.c sort_small.c double_operations.c move_b.c move_a.c

FT_PRINTF_FILES = ft_printf/libftprintf.c ft_printf/handle_str.c ft_printf/handle_char.c ft_printf/handle_dec.c ft_printf/handle_unsigned.c ft_printf/handle_hex.c ft_printf/handle_pointer.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_MAKEFILE = $(LIBFT_DIR)/Makefile

OBJ = $(SRC:.c=.o)

FT_PRINTF_OFILES = $(FT_PRINTF_FILES:.c=.o)

FT_PRINTF = -I./ft_printf

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(FT_PRINTF_OFILES) $(LIBFT)
	$(CC) $(OBJ) $(FT_PRINTF_OFILES) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJ) $(FT_PRINTF_OFILES)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
