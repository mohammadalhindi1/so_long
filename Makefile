# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 20:38:42 by malhendi          #+#    #+#              #
#    Updated: 2025/11/03 20:38:45 by malhendi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    := so_long

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -Iincludes -Iincludes/libft
MLXFLAGS := -lmlx -lXext -lX11 -lm

SRCDIR  = srcs
OBJ_DIR = obj
LIBPATH = includes/libft

GREEN   = \033[0;32m
RED     = \033[0;31m
RESET   = \033[0m

RM      = rm -rf

SRCS_COMMON := \
	assets.c \
	display_linux.c	\
	enemy/enemy.c \
	enemy/enemy_utils.c \
	input.c \
	main.c \
	map/map_alloc.c \
	map/map_check.c \
	map/map_loader.c \
	map/map_read.c \
	map/map_utils.c \
	map/map_path.c \
	render.c

SRCS := $(addprefix $(SRCDIR)/,$(SRCS_COMMON))
OBJS := $(SRCS:$(SRCDIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBPATH)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBPATH) -lft $(MLXFLAGS) -o $(NAME)
	@echo "$(GREEN)Done ✔$(RESET)"

$(OBJ_DIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBPATH)
	@echo "$(RED)Deleting $(OBJ_DIR)...$(RESET)"
	@$(RM) $(OBJ_DIR)
	@echo "$(RED)Done ✔$(RESET)"

fclean: clean
	@$(MAKE) fclean -C $(LIBPATH)
	@echo "$(RED)Deleting $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(RED)Done ✔$(RESET)"

re: fclean all

.PHONY: all clean fclean re
