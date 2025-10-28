/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:35:21 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 03:35:22 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*join_asset(const char *name)
{
	static char	buf[256];
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (ASSET_DIR[i] && i < 200)
	{
		buf[i] = ASSET_DIR[i];
		i++;
	}
	while (name[j] && i + j < 255)
	{
		buf[i + j] = name[j];
		j++;
	}
	buf[i + j] = '\0';
	return (buf);
}

static void	*load_xpm(t_app *a, const char *name)
{
	int		w;
	int		h;
	char	*path;
	void	*img;

	w = 0;
	h = 0;
	path = join_asset(name);
	img = mlx_xpm_file_to_image(a->mlx, path, &w, &h);
	if (!img)
	{
		fprintf(stderr, "Error\nfailed to load: %s\n", path);
		close_game(a);
	}
	if (w != TILE || h != TILE)
	{
		fprintf(stderr, "Error\nsize %s\n", path);
		close_game(a);
	}
	a->img.w = w;
	a->img.h = h;
	return (img);
}

void	load_images(t_app *a)
{
	a->img.floor = load_xpm(a, "floor.xpm");
	a->img.wall = load_xpm(a, "wall.xpm");
	a->img.player = load_xpm(a, "player.xpm");
	a->img.exit_ = load_xpm(a, "exit.xpm");
	a->img.collect = load_xpm(a, "collectible.xpm");
	a->img.enemy_v = load_xpm(a, "enemy_v.xpm");
	a->img.enemy_h = load_xpm(a, "enemy_h.xpm");
}
