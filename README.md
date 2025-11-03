# So_long — Starter Guide (42 Cursus)

*Author: Mohammad Alhindi*

---

## 🧩 What is So_long?

A small 2D game written in **C** using **MiniLibX (MLX)** — a minimal graphics **API (Application Programming Interface)**. The player (P) collects all collectibles (C) and exits through (E) without walking through walls (1). Empty tiles are (0).

**Map Alphabet:**
```php
0 → empty    1 → wall
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
├── assets.c
├── display_linux.c
├── enemy/
│   ├── enemy.c
│   └── enemy_utils.c
├── input.c
├── main.c
├── map/
│   ├── map_check.c
│   ├── map_loader.c
│   ├── map_path.c      # flood fill (DFS)
│   ├── map_read.c      # robust GNL wrapper (handles CRLF)
│   └── map_utils.c
├── print_get_next/
│   ├── ft_conv_char_str.c
│   ├── ft_conv_numbers.c
│   ├── ft_printf.c
│   ├── get_next_line.c
│   └── get_next_line_utils.c
├── render.c
├── so_long.h
├── maps/
│   ├── map.ber
│   └── bonus.ber
└── Makefile
```

## ⚙️ Makefile Build

```make
make            # build
make clean      # remove objects
make fclean     # remove objects + binary
make re         # full rebuild
```

## 🧠 Header Example

```c
#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "mlx.h"

typedef struct s_game {
    char **map; int w; int h;
    int px; int py;
    int c_total; int c_left; int moves;
    void *mlx; void *win;
} t_game;

int  load_map(const char *path, t_game *g);
int  check_map_shape_chars_counts(t_game *g);
int  check_map_walls(t_game *g);
int  validate_reachable(t_game *g);
int  render_all(t_game *g);
int  on_key(int kc, t_game *g);
int  on_destroy(t_game *g);
void free_map(char **map);
void fatal(const char *msg);
#endif
```

---

## 🪟 Minimal MLX Boot Example

```c
#include "so_long.h"

int on_destroy(t_game *g) {
    (void)g;
    exit(0);
    return 0;
}

int on_key(int kc, t_game *g) {
#ifdef __APPLE__
    if (kc == 53)
        on_destroy(g);        // macOS ESC
#else
    if (kc == 65307)
        on_destroy(g);        // Linux ESC
#endif
    return 0;
}

int main(int ac, char **av)
{
    t_game g; (void)av;
    if (ac != 2)
        return (write(2, "Usage: ./so_long maps/a.ber\n", 30), 1);
    g.mlx = mlx_init();
    g.win = mlx_new_window(g.mlx, 640, 480, "so_long");
    mlx_hook(g.win, 17, 0, on_destroy, &g);
    mlx_hook(g.win, 2, 1L<<0, on_key, &g);
    mlx_loop(g.mlx);
    return 0;
}
```

**Result:** opens a blank window, closes cleanly on ESC or X.

---

## 📜 Why Get Next Line?

`get_next_line()` lets you read a map file **line‑by‑line** without knowing its size in advance. It simplifies parsing for rectangular validation and storage in `char **map`.

Example:

```c
int fd = open("maps/a.ber", O_RDONLY);
char *line;
while ((line = get_next_line(fd))) {
    printf("%s", line);
    free(line);
}
close(fd);
```

---

## 🔍 Map Rules Recap

1. Rectangular shape (all lines equal length).
2. Enclosed by walls (top/bottom and left/right all `1`).
3. One `P`, one `E`, at least one `C`.
4. Valid path from `P` → all `C` → `E`.
5. Allowed characters: `0,1,C,E,P`.

Invalid input must exit cleanly:

```
Error
map is not rectangular
```

---

## 🧮 Movement Logic (W/A/S/D)

* Compute target position `(tx, ty)`.
* If tile = `1` → blocked.
* If tile = `C` → decrement `c_left`, turn it to `0`.
* Move player, increment `moves`, print counter.
* If tile = `E` and `c_left == 0` → clean exit.

**Key codes:**

* ESC = 65307 (Linux)
* ESC = 53 (macOS)

---

## 🧠 Path Checking

Use a **Flood Fill (DFS)** algorithm:

```c
// pseudo‑logic
start from P
visit (x, y) if in bounds and tile ∈ {0,C,E}
mark visited, continue in 4 directions
count reachable C’s, check if E reachable
```

If unreachable: `Error\nno valid path`.

---

## 🧱 Rendering Tiles

Load textures:

```c
img_wall = mlx_xpm_file_to_image(mlx, "textures/wall.xpm", &w, &h);
mlx_put_image_to_window(mlx, win, img_wall, x*TILE, y*TILE);
```

For a quick prototype, draw solid colors or placeholder squares.

---

## 🧹 Clean Exit

Always free:

* `free_map(map)`
* `mlx_destroy_image` for each image
* `mlx_destroy_window`

**No leaks!** Test:

```
valgrind --leak-check=full ./so_long maps/a.ber
```

---

## 🗺️ Example Maps

**Valid:**

```
11111
1P0C1
100E1
11111
```

**Invalid (not rectangular):**

```
1111
1P0C1
100E1
11111
```

**Invalid (open borders):**

```
11111
1P0C1
100E0
11101
```

**Invalid (duplicate P/E):**

```
11111
1PP01
10EE1
11111
```

## 🧭 Quick Roadmap

1. Open/close window with MLX.
2. Read map using GNL.
3. Validate rules.
4. Flood Fill path check.
5. Render tiles.
6. Add movement & move counter.
7. Clean exit + Valgrind.

---

## 📚 Glossary

| Term        | Meaning                           |
| ----------- | --------------------------------- |
| **MLX**     | MiniLibX (graphics library)       |
| **GNL**     | Get Next Line (line reader)       |
| **API**     | Application Programming Interface |
| **UI**      | User Interface                    |
| **DFS/BFS** | Graph traversal algorithms        |

---
**From Mohammad Alhindi**
───────────────────────────────
© 2025 Mohammad Alhindi — All Rights Reserved  
Reusing or copying this code without permission is not cool — be original.
───────────────────────────────
