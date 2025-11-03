/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:11:38 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/02 05:15:04 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

static int	safe_mul_size(size_t a, size_t b, size_t *out)
{
	if (a != 0 && b > (size_t)-1 / a)
		return (0);
	*out = a * b;
	return (1);
}

void	push_enemy(t_app *a, t_enemy e)
{
	t_enemy	*old;
	t_enemy	*tmp;
	size_t	bytes;
	int		i;

	if (!a || a->en_count < 0)
		return ;
	old = a->en;
	if (!safe_mul_size((size_t)(a->en_count + 1), sizeof(t_enemy), &bytes))
		return ;
	tmp = (t_enemy *)malloc(bytes);
	if (!tmp)
		return ;
	i = 0;
	while (i < a->en_count)
	{
		tmp[i] = old[i];
		i++;
	}
	tmp[i] = e;
	a->en = tmp;
	a->en_count++;
	free(old);
}

int	can_step(t_app *a, int nx, int ny)
{
	if (!a || !a->map || a->mw <= 0 || a->mh <= 0)
		return (0);
	if (nx < 0 || ny < 0 || nx >= a->mw || ny >= a->mh)
		return (0);
	if (a->map[ny][nx] == '1')
		return (0);
	return (1);
}

void	rev_dir(t_enemy *e)
{
	if (!e)
		return ;
	e->dx *= -1;
	e->dy *= -1;
}
