/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:25 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/30 23:13:26 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef TILE
#  define TILE 64
# endif

# ifndef ENEMY_MS
#  define ENEMY_MS 500
# endif

# define ASSET_DIR "assets/"

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

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

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
}			t_keys;

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
	int		tick_p;
	int		tick_e;
	int		dirty;
	t_keys	keys;
	t_imgs	img;
	t_enemy	*en;
	int		en_count;
}			t_app;

/* map_loader.c + map_utils.c + map_check.c + map_read.c */
t_mapinfo	load_map(const char *path);
void		free_map(char **map);
int			slen(const char *s);
char		*sddup(const char *s, int n);
char		**read_rows(int fd, int *out_h, int *out_w);
int			validate_map(char **r, int h, int w, t_mapinfo *o);
void		free_rows_partial(char **r, int n);
int			copy_rows(char **dst, char **src, int n);

/* enemy.c + enemy_utils.c */
void		enemies_init(t_app *a);
int			enemies_update(t_app *a);
int			player_dead(t_app *a);
int			can_step(t_app *a, int nx, int ny);
void		rev_dir(t_enemy *e);

/* input.c */
int			on_key_down(int key, t_app *a);
int			on_key_up(int key, t_app *a);
void		player_update(t_app *a);

/* render.c + assets.c */
void		load_images(t_app *a);
void		render_all(t_app *a);
void		destroy_images(t_app *a);
void		destroy_display(t_app *a);

/* main.c */
int			close_game(t_app *a);

#endif
