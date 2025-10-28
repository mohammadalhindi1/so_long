/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:33:02 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 02:33:03 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	loop_hook(t_app *a)
{
	enemies_update(a);
	if (player_dead(a))
	{
		fprintf(stderr, "You Died!\n");
		close_game(a);
	}
	if (a->dirty)
	{
		mlx_clear_window(a->mlx, a->win);
		render_all(a);
		a->dirty = 0;
	}
	usleep(16000);
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
}

static int	start_window(t_app *a)
{
	a->win = mlx_new_window(a->mlx, a->mw * TILE, a->mh * TILE, "so_long");
	if (!a->win)
		return (1);
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
	if (a->en)
		free(a->en);
	if (a->map)
		free_map(a->map);
	if (a->win)
		mlx_destroy_window(a->mlx, a->win);
	exit(0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mapinfo	mi;
	t_app		a;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s maps/level.ber\n", av[0]);
		return (1);
	}
	a.mlx = mlx_init();
	if (!a.mlx)
		return (1);
	mi = load_map(av[1]);
	if (!mi.map)
		return (1);
	setup_app(&a, mi);
	return (start_window(&a));
}
