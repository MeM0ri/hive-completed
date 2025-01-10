NAME 		= libftprintf.a
CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror -Isrcs -Iinclude
RM			= rm -rf

VPATH 		= srcs
SRCS 	= ft_printf.c ft_putchar.c ft_putstr.c ft_putptr.c ft_putnbr.c ft_putui.c ft_puthex.c

OBJS 		= $(addprefix obj/,$(SRCS:.c=.o))

$(NAME): 	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all: 		$(NAME)

obj:
			mkdir -p obj

obj/%.o: 	%.c | obj
			mkdir -p $(dir $@)
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) obj

fclean: 	clean
			$(RM) $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
