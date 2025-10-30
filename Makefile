NAME    := so_long
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I.

UNAME_S := $(shell uname -s)

SRCS_COMMON := \
	main.c \
	render.c \
	assets.c \
	input.c \
	enemy.c \
	enemy_utils.c \
	map_loader.c \
	map_read.c \
	map_utils.c \
	map_check.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_printf.c \
	ft_conv_char_str.c \
	ft_conv_numbers.c

ifeq ($(UNAME_S), Darwin)
	SRCS := $(SRCS_COMMON) display_apple.c
	MLXFLAGS := -lmlx -framework OpenGL -framework AppKit
else
	SRCS := $(SRCS_COMMON) display_linux.c
	MLXFLAGS := -lmlx -lXext -lX11 -lm
endif

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

