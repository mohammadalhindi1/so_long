/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_ustils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:35:18 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 03:35:19 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy	make_enemy(int x, int y, int dx, int dy)
{
	t_enemy	e;

	e.x = x;
	e.y = y;
	e.dx = dx;
	e.dy = dy;
	e.sx = x;
	e.sy = y;
	e.range = 4;
	e.moved = 0;
	return (e);
}

void	push_enemy(t_app *a, t_enemy e)
{
	t_enemy	*tmp;
	int		i;

	tmp = (t_enemy *)malloc(sizeof(t_enemy) * (a->en_count + 1));
	if (!tmp)
		return ;
	i = 0;
	while (i < a->en_count)
	{
		tmp[i] = a->en[i];
		i++;
	}
	tmp[i] = e;
	free(a->en);
	a->en = tmp;
	a->en_count++;
}

int	can_step(t_app *a, int nx, int ny)
{
	if (nx < 0 || ny < 0 || nx >= a->mw || ny >= a->mh)
		return (0);
	if (a->map[ny][nx] == '1')
		return (0);
	return (1);
}

void	rev_dir(t_enemy *e)
{
	e->dx *= -1;
	e->dy *= -1;
}
