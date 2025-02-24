# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/07 13:53:38 by alfokin           #+#    #+#              #
#    Updated: 2025/02/24 13:54:24 by alfokin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables
CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -Iinclude -Isrc -Ofast
RM					=	rm -rf
SERVER				=	server
CLIENT				=	client
NAME				=	$(SERVER) $(CLIENT)

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
VPATH				=	src:src/server:src/client:include
SERVER_INC			=	server.h
SERVER_SRC			=	server.c
CLIENT_INC			=	client.h
CLIENT_SWAP_SRC		=	client.c

# Rules
all:				$(SERVER) $(CLIENT)

obj:
					mkdir -p obj

LIB					=	$(LIBFT_FILE) $(FT_PRINTF_FILE)
SERVER_OBJ			=	$(SERVER_SRC:%.c=obj/server/%.o)
CLIENT_OBJ			= 	$(CLIENT_SRC:%.c=obj/client/%.o)

$(LIBFT_FILE):
					$(MAKE_LIB) $(LIBFT_DIR)
$(FT_PRINTF_FILE):
					$(MAKE_LIB) $(FT_PRINTF_DIR)

$(SERVER_OBJ):		obj/server/%.o: %.c $(SERVER_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(CLIENT_OBJ):		obj/client/%.o: %.c $(CLIENT_INC)
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) -c $< -o $@

$(SERVER):			$(LIB) $(SERVER_OBJ)
					$(CC) $(CFLAGS) -no-pie -o $(SERVER) $(SERVER_OBJ) $(LIB)

$(CLIENT):			$(LIB) $(CLIENT_OBJ)
					$(CC) $(CFLAGS) -no-pie -o $(CLIENT) $(CLIENT_OBJ) $(LIB)

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
