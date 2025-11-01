# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/01 00:52:01 by malhendi          #+#    #+#              #
#    Updated: 2025/11/01 01:17:21 by malhendi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I.
MLXFLAGS := -lmlx -lXext -lX11 -lm
HEADERS = so_long.h ft_printf.h get_next_line.h
OBJ_DIR = obj
GREEN   	= \033[0;32m
RED    		= \033[0;31m
RESET   	= \033[0m
SRCS_COMMON := \
	assets.c \
	display_linux.c	\
	enemy/enemy.c \
	enemy/enemy_utils.c \
	print_get_next/ft_conv_char_str.c \
	print_get_next/ft_conv_numbers.c \
	print_get_next/ft_printf.c \
	print_get_next/get_next_line.c \
	print_get_next/get_next_line_utils.c \
	input.c \
	main.c \
	map/map_check.c \
	map/map_loader.c \
	map/map_read.c \
	map/map_utils.c \
	map/map_path.c \
	render.c

SRCS := $(SRCS_COMMON) 
OBJS := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)Done ✔$(RESET)"

$(OBJ_DIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Deleting $(OBJ_DIR)...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)Done ✔$(RESET)"

fclean: clean
	@echo "$(RED)Deleting $(NAME)...$(RESET)"
	@rm -f $(NAME)
	@echo "$(RED)Done ✔$(RESET)"

re: fclean all

.PHONY: all clean fclean re
