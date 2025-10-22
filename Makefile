NAME := miniwin
CC := cc
CFLAGS := -Wall -Wextra -Werror

SRCS := main.c
OBJS := $(SRCS:.c=.o)

MLX_FLAGS := -lmlx -lXext -lX11 -lm

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean: ; rm -f $(OBJS)

fclean: clean ; rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

