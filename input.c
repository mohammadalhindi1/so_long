/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:33:06 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 02:33:07 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	try_step(t_app *a, int dx, int dy)
{
	int	nx;
	int	ny;

	nx = a->px + dx;
	ny = a->py + dy;
	if (nx < 0 || ny < 0 || nx >= a->mw || ny >= a->mh)
		return ;
	if (a->map[ny][nx] == '1')
		return ;
	a->px = nx;
	a->py = ny;
	a->moves++;
	a->dirty = 1;
	printf("move: %d\n", a->moves);
	if (a->map[ny][nx] == 'C')
	{
		a->map[ny][nx] = '0';
		a->collects--;
	}
	if (a->map[ny][nx] == 'E' && a->collects == 0)
	{
		printf("GG in %d\n", a->moves);
		close_game(a);
	}
}

void	player_update(t_app *a)
{
	(void)a;
}

int	on_key_down(int k, t_app *a)
{
	if (k == KEY_ESC)
		return (close_game(a), 0);
	if (k == KEY_W || k == KEY_UP)
		try_step(a, 0, -1);
	if (k == KEY_S || k == KEY_DOWN)
		try_step(a, 0, 1);
	if (k == KEY_A || k == KEY_LEFT)
		try_step(a, -1, 0);
	if (k == KEY_D || k == KEY_RIGHT)
		try_step(a, 1, 0);
	return (0);
}

int	on_key_up(int k, t_app *a)
{
	(void)k;
	(void)a;
	return (0);
}
