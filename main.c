/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:12:39 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/30 23:12:41 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	loop_hook(t_app *a)
{
	enemies_update(a);
	if (player_dead(a))
	{
		ft_printf("You Died!\n");
		close_game(a);
	}
	if (a->dirty)
	{
		if (a->mlx && a->win)
		{
			mlx_clear_window(a->mlx, a->win);
			render_all(a);
		}
		a->dirty = 0;
	}
	return (0);
}

static void	setup_app(t_app *a, t_mapinfo mi)
{
	a->map = mi.map;
	a->mw = mi.w;
	a->mh = mi.h;
	a->px = mi.px;
	a->py = mi.py;
	a->collects = mi.collects;
	a->moves = 0;
	a->keys.w = 0;
	a->keys.a = 0;
	a->keys.s = 0;
	a->keys.d = 0;
	a->en = NULL;
	a->en_count = 0;
	a->tick_p = 0;
	a->tick_e = 0;
	a->dirty = 1;
	a->img.floor = NULL;
	a->img.wall = NULL;
	a->img.player = NULL;
	a->img.exit_ = NULL;
	a->img.collect = NULL;
	a->img.enemy_v = NULL;
	a->img.enemy_h = NULL;
}

static int	start_window(t_app *a)
{
	if (!a || !a->mlx)
		return (1);
	a->win = mlx_new_window(a->mlx, a->mw * TILE, a->mh * TILE, "so_long");
	if (!a->win)
		return (close_game(a), 1);
	load_images(a);
	enemies_init(a);
	mlx_hook(a->win, 17, 0, close_game, a);
	mlx_hook(a->win, 2, (1L << 0), on_key_down, a);
	mlx_hook(a->win, 3, (1L << 1), on_key_up, a);
	mlx_loop_hook(a->mlx, loop_hook, a);
	mlx_loop(a->mlx);
	return (0);
}

int	close_game(t_app *a)
{
	if (!a)
	{
		exit(0);
		return (0);
	}
	if (a->en)
	{
		free(a->en);
		a->en = NULL;
	}
	if (a->map)
	{
		free_map(a->map);
		a->map = NULL;
	}
	destroy_images(a);
	if (a->mlx && a->win)
	{
		mlx_destroy_window(a->mlx, a->win);
		a->win = NULL;
	}
	destroy_display(a);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mapinfo	mi;
	t_app		a;

	if (ac != 2)
	{
		write(2, "Usage: ./so_long maps/level.ber\n", 32);
		return (1);
	}
	mi.map = NULL;
	a.mlx = mlx_init();
	if (!a.mlx)
	{
		write(2, "Error\nmlx_init failed\n", 22);
		return (1);
	}
	mi = load_map(av[1]);
	if (!mi.map)
		return (close_game(&a), 1);
	setup_app(&a, mi);
	return (start_window(&a));
}
