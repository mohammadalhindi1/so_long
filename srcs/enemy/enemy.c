/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:11:46 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/03 19:13:09 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
				if (!push_enemy(a, make_enemy(x, y, 0, 1)))
					close_game(a);
				a->map[y][x] = '0';
			}
			else if (a->map[y][x] == 'H')
			{
				if (!push_enemy(a, make_enemy(x, y, 1, 0)))
					close_game(a);
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

static long	now_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

int	enemies_update(t_app *a)
{
	static long	prev_ms;
	long		cur;
	int			i;
	int			any;

	cur = now_ms();
	if (prev_ms == 0)
		prev_ms = cur;
	if (cur - prev_ms < ENEMY_MS)
		return (0);
	prev_ms = cur;
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
