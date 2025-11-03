/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:25 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/03 19:06:50 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/includes/ft_printf.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# ifndef TILE
#  define TILE 64
# endif

# ifndef ENEMY_MS
#  define ENEMY_MS 500
# endif

# ifndef ASSET_DIR
#  define ASSET_DIR "assets/"
# endif

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

typedef struct s_imgs
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*exit_;
	void	*collect;
	void	*enemy_v;
	void	*enemy_h;
	int		w;
	int		h;
}			t_imgs;

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		range;
	int		moved;
}			t_enemy;

typedef struct s_mapinfo
{
	char	**map;
	int		w;
	int		h;
	int		px;
	int		py;
	int		collects;
}			t_mapinfo;

typedef struct s_ff
{
	char	**m;
	int		h;
	int		w;
	int		got_c;
	int		hit_e;
}			t_ff;

typedef struct s_app
{
	void	*mlx;
	void	*win;

	char	**map;
	int		mw;
	int		mh;

	int		px;
	int		py;
	int		moves;
	int		collects;
	int		dirty;

	t_imgs	img;

	t_enemy	*en;
	int		en_count;

	long	last_enemy_ms;
	int		game_over;

	int		up;
	int		down;
	int		left;
	int		right;
}			t_app;

typedef struct s_rows
{
	char	**rows;
	int		cap;
	int		h;
}			t_rows;

/* ----------------------- MAP -------------------------- */

t_mapinfo	load_map(const char *path);
char		**read_rows(int fd, int *out_h, int *out_w);
int			validate_map(char **r, int h, int w, t_mapinfo *o);
int			validate_paths(char **r, int h, int w, t_mapinfo o);
void		free_map(char **map);

/* helpers from map_utils.c */
int			trim_newline_len(char *line);
char		*sddup(const char *s, int n);
int			copy_rows(char **dst, char **src, int n);
void		free_rows_partial(char **rows, int n);

/* helpers for row allocation (map_alloc.c) */
int			rows_reserve(char ***rows, int *cap, int need, int used);
int			rows_finalize(char ***rows, int *cap, int h);

void		enemies_init(t_app *a);
int			enemies_update(t_app *a);
int			player_dead(t_app *a);
int			can_step(t_app *a, int nx, int ny);
int			push_enemy(t_app *a, t_enemy e);
void		rev_dir(t_enemy *e);
t_enemy		make_enemy(int x, int y, int dx, int dy);

/* ----------------------- INPUT ------------------------ */

int			on_key_down(int key, t_app *a);
int			on_key_up(int key, t_app *a);
void		player_update(t_app *a);

/* ----------------------- RENDER ----------------------- */

void		load_images(t_app *a);
void		render_all(t_app *a);
void		destroy_images(t_app *a);
void		destroy_display(t_app *a);

/* ----------------------- MAIN ------------------------- */

int			close_game(t_app *a);

#endif
