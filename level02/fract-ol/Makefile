# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 13:53:38 by alfokin           #+#    #+#              #
#    Updated: 2025/03/17 16:03:21 by alfokin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc 
RM					=	rm -rf
FRACTOL				=	fractol
NAME				=	$(FRACTOL)

# Libraries
LIBFT				=	libft.a
LIBFT_DIR			=	lib/libft
LIBFT_FILE			=	$(LIBFT_DIR)/$(LIBFT)
CFLAGS				+=	-I $(LIBFT_DIR)/include

FT_PRINTF			=	ft_printf.a
FT_PRINTF_DIR		=	lib/ft_printf
FT_PRINTF_FILE		=	$(FT_PRINTF_DIR)/$(FT_PRINTF)
CFLAGS				+=	-I $(FT_PRINTF_DIR)/include

LIBMLX				=	libmlx_Linux.a
LIBMLX_DIR			=	lib/minilibx
LIBMLX_FILE			=	$(LIBMLX_DIR)/$(LIBMLX)
CFLAGS				+=	-I $(LIBMLX_DIR)
MLXFLAGS			=	-L$(LIBMLX_DIR) -lmlx_Linux -L/usr/lib -I$(LIBMLX_DIR) -lXext -lX11 -lm -lz

MAKE_LIB			=	make --no-print-directory -C

# Source and Object Files
VPATH				=	src:include
FRACTOL_INC			=	fractol.h keys.h
FRACTOL_SRC			=	fractol.c fractals.c fractal_utils.c\
						viewport.c viewport_utils.c utils.c\
						events.c threads.c controls.c

# Rules
all:				$(FRACTOL)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_FILE) $(FT_PRINTF_FILE) $(LIBMLX_FILE)
FRACTOL_OBJ			=	$(FRACTOL_SRC:%.c=obj/%.o)

$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)
$(FT_PRINTF_FILE):
					$(MAKE_LIB) $(FT_PRINTF_DIR)
$(LIBMLX_FILE):
					$(MAKE_LIB) $(LIBMLX_DIR)

$(FRACTOL_OBJ):		obj/%.o: %.c $(FRACTOL_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(FRACTOL):			$(LIB) $(FRACTOL_OBJ)
					$(CC) $(CFLAGS) -no-pie -o $(FRACTOL) $(FRACTOL_OBJ) $(LIB) $(MLXFLAGS)

lib_clean:
					$(MAKE_LIB) $(LIBFT_DIR) clean
					$(MAKE_LIB) $(FT_PRINTF_DIR) clean
					$(MAKE_LIB) $(LIBMLX_DIR) clean

lib_fclean:
					$(MAKE_LIB) $(LIBFT_DIR) fclean
					$(MAKE_LIB) $(FT_PRINTF_DIR) fclean
					$(MAKE_LIB) $(LIBMLX_DIR) clean

clean:				lib_clean
					$(RM) obj

fclean:				clean lib_fclean
					$(RM) $(NAME)

re:					fclean all

.SILENT:

.PHONY:				all bonus lib_clean lib_fclean clean fclean re
