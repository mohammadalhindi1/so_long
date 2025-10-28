/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:33:19 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 02:33:20 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* من enemy_utils.c */
t_enemy		make_enemy(int x, int y, int dx, int dy);
void		push_enemy(t_app *a, t_enemy e);
int			can_step(t_app *a, int nx, int ny);
void		rev_dir(t_enemy *e);

void	enemies_init(t_app *a)
{
	int	y;
	int	x;

	y = 0;
	while (y < a->mh)
	{
		x = 0;
		while (x < a->mw)
		{
			if (a->map[y][x] == 'V')
			{
				push_enemy(a, make_enemy(x, y, 0, 1));
				a->map[y][x] = '0';
			}
			else if (a->map[y][x] == 'H')
			{
				push_enemy(a, make_enemy(x, y, 1, 0));
				a->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

static int	move_enemy(t_app *a, t_enemy *e)
{
	int	nx;
	int	ny;

	nx = e->x + e->dx;
	ny = e->y + e->dy;
	if (!can_step(a, nx, ny))
	{
		rev_dir(e);
		return (0);
	}
	e->x = nx;
	e->y = ny;
	e->moved++;
	if (e->moved >= e->range)
	{
		rev_dir(e);
		e->moved = 0;
	}
	return (1);
}

int	enemies_update(t_app *a)
{
	int	i;
	int	any;

	if (++a->tick_e < ENEMY_TICK)
		return (0);
	a->tick_e = 0;
	i = 0;
	any = 0;
	while (i < a->en_count)
	{
		if (move_enemy(a, &a->en[i]))
			any = 1;
		i++;
	}
	if (any)
		a->dirty = 1;
	return (any);
}

int	player_dead(t_app *a)
{
	int	i;

	i = 0;
	while (i < a->en_count)
	{
		if (a->en[i].x == a->px && a->en[i].y == a->py)
			return (1);
		i++;
	}
	return (0);
}
