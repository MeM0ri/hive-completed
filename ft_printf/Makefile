NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = srcs
SRC_FILES = ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_putui.c ft_puthex.c
OBJS = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
