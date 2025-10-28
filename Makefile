NAME    = miniwin
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I.

SRCS = main.c map_loader.c map_utils.c map_read.c map_check.c input.c render.c assets.c \
       enemy.c enemy_utils.c \
       get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
 MLX = -lmlx -framework OpenGL -framework AppKit
else
 MLX = -lmlx -lXext -lX11 -lm
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

