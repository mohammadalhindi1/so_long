# So_long — Starter Guide (42 Cursus)

*Author: Mohammad Alhindi*

---

## 🧩 What is So_long?

A small 2D game written in **C** using **MiniLibX (MLX)** — a minimal graphics **API (Application Programming Interface)**. The player (P) collects all collectibles (C) and exits through (E) without walking through walls (1). Empty tiles are (0).

**Map Alphabet:**

```
0 → empty
1 → wall
C → collectible
E → exit
P → player start
```

### 🎯 Mandatory goals

* Parse a `.ber` map file.
* Validate the map: rectangular, closed by walls, symbols count, valid path.
* Render the map with **MiniLibX**.
* Move using **W/A/S/D** (or arrows).
* Print the move counter in the terminal.
* Clean exit on **ESC** and window **X** (no leaks, no crashes).

---

## 🧱 Project Structure

```
so_long/
│── include/
│   └── so_long.h
│── src/
│   ├── main.c
│   ├── map_load.c
│   ├── map_check.c
│   ├── path_check.c
│   ├── render.c
│   ├── input.c
│   └── free_all.c
│── gnl/
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── get_next_line.h
│── maps/
│   └── a.ber
│── textures/
│   ├── wall.xpm
│   ├── floor.xpm
│   ├── player.xpm
│   ├── exit.xpm
│   └── coin.xpm
└── Makefile
```

> Each function ≤ 25 lines, ≤ 5 functions per file (42 Norm). Split logic into small helpers.

---

## ⚙️ Makefile Example

**Linux (X11)**:

```make
NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ignl
SRCS = src/main.c src/map_load.c src/map_check.c src/path_check.c \
       src/render.c src/input.c src/free_all.c \
       gnl/get_next_line.c gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
MLX_FLAGS = -lmlx -lXext -lX11 -lm

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re:
```
