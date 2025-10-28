/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:32:19 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 02:32:20 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put(t_app *a, void *im, int x, int y)
{
	mlx_put_image_to_window(a->mlx, a->win, im, x * TILE, y * TILE);
}

static void	render_map(t_app *a)
{
	int	y;
	int	x;

	y = 0;
	while (y < a->mh)
	{
		x = 0;
		while (x < a->mw)
		{
			put(a, a->img.floor, x, y);
			if (a->map[y][x] == '1')
				put(a, a->img.wall, x, y);
			else if (a->map[y][x] == 'E')
				put(a, a->img.exit_, x, y);
			else if (a->map[y][x] == 'C')
				put(a, a->img.collect, x, y);
			x++;
		}
		y++;
	}
}

void	render_all(t_app *a)
{
	int		i;
	void	*im;

	render_map(a);
	i = 0;
	while (i < a->en_count)
	{
		im = a->img.enemy_v;
		if (a->en[i].dx != 0)
			im = a->img.enemy_h;
		put(a, im, a->en[i].x, a->en[i].y);
		i++;
	}
	put(a, a->img.player, a->px, a->py);
}
