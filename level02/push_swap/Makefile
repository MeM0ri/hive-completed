# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 13:53:38 by alfokin           #+#    #+#              #
#    Updated: 2025/02/07 17:06:44 by alfokin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc -Ofast
RM					=	rm -rf
CHECKER				=	checker
PUSH_SWAP			=	push_swap.a
NAME				=	$(PUSH_SWAP) $(CHECKER)

# Libraries
LIBFT				=	libft.a
LIBFT_DIR			=	lib/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

FT_PRINTF			=	ft_printf.a
FT_PRINTF_DIR		=	lib/ft_printf
FT_PRINTF_FILE		=	$(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
VPATH				=	src:src/stack:src/push_swap:src/checker_bonus:include
STACK_INC			=	stack.h
STACK_SRC			=	error_handler.c free_data.c init_checks.c init_utils.c \
						operation_swap.c operation_push.c operation_rotate.c \
						operation_reverse_rotate.c operation_checks.c \
						operation_utils.c stack_utils.c
PUSH_SWAP_INC		=	$(STACK_INC) push_swap.h
PUSH_SWAP_SRC		=	$(STACK_SRC) chunk_sort_utils.c chunk_sort.c \
						chunk_split_utils.c chunk_split.c easy_sort.c \
						move_operations.c optimization_operations.c push_swap.c \
						sort_one_operations.c sort_three_operations.c \
						sort_two_operations.c sort_utils.c sort.c
CHECKER_INC			=	$(STACK_INC) checker_bonus.h
CHECKER_SRC			=	$(STACK_SRC) checker_bonus.c checker_utils_bonus.c

# Rules
all:				$(PUSH_SWAP)

bonus:				$(CHECKER)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_FILE) $(FT_PRINTF_FILE)
PUSH_SWAP_OBJ		=	$(PUSH_SWAP_SRC:%.c=obj/push_swap/%.o)
CHECKER_OBJ			= 	$(CHECKER_SRC:%.c=obj/checker/%.o)

$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)
$(FT_PRINTF_FILE):
					$(MAKE_LIB) $(FT_PRINTF_DIR)

$(PUSH_SWAP_OBJ):	obj/push_swap/%.o: %.c $(PUSH_SWAP_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(CHECKER_OBJ):		obj/checker/%.o: %.c $(CHECKER_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP):		$(LIB) $(PUSH_SWAP_OBJ)
					$(CC) $(CFLAGS) -no-pie -o $(PUSH_SWAP) $(PUSH_SWAP_OBJ) $(LIB)

$(CHECKER):			$(LIB) $(CHECKER_OBJ)
					$(CC) $(CFLAGS) -no-pie -o $(CHECKER) $(CHECKER_OBJ) $(LIB)

lib_clean:
					$(MAKE_LIB) $(LIBFT_DIR) clean
					$(MAKE_LIB) $(FT_PRINTF_DIR) clean

lib_fclean:
					$(MAKE_LIB) $(LIBFT_DIR) fclean
					$(MAKE_LIB) $(FT_PRINTF_DIR) fclean

clean:				lib_clean
					$(RM) obj

fclean:				clean lib_fclean
					$(RM) $(NAME)

re:					fclean all

.SILENT:

.PHONY:				all bonus lib_clean lib_fclean clean fclean re
