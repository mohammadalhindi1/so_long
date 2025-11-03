/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:12:48 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/01 00:44:58 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_rect(char **m, int h, int w)
{
	int	y;

	y = 0;
	while (y < h)
	{
		if ((int)ft_strlen(m[y]) != w)
			return (0);
		y++;
	}
	return (1);
}

static int	is_walled(char **m, int h, int w)
{
	int	x;
	int	y;

	x = 0;
	while (x < w)
	{
		if (m[0][x] != '1' || m[h - 1][x] != '1')
			return (0);
		x++;
	}
	y = 0;
	while (y < h)
	{
		if (m[y][0] != '1' || m[y][w - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

static int	scan_row(char *row, int y, t_mapinfo *o, int w)
{
	int	x;

	x = 0;
	while (x < w)
	{
		if (row[x] == 'P')
		{
			o->px = x;
			o->py = y;
			o->collects += 1000000;
		}
		else if (row[x] == 'E')
			o->collects += 100000;
		else if (row[x] == 'C')
			o->collects++;
		else if (row[x] != '0' && row[x] != '1' && row[x] != 'V'
			&& row[x] != 'H')
			return (0);
		x++;
	}
	return (1);
}

int	validate_map(char **r, int h, int w, t_mapinfo *o)
{
	int	y;
	int	cp;
	int	ce;
	int	cc;

	if (!is_rect(r, h, w) || !is_walled(r, h, w))
		return (0);
	o->collects = 0;
	y = 0;
	while (y < h)
	{
		if (!scan_row(r[y], y, o, w))
			return (0);
		y++;
	}
	cp = o->collects / 1000000;
	ce = (o->collects % 1000000) / 100000;
	cc = o->collects % 100000;
	if (cp != 1 || ce != 1 || cc < 1)
		return (0);
	o->collects = cc;
	if (!validate_paths(r, h, w, *o))
		return (0);
	return (1);
}
