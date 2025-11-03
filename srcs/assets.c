/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:35:21 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/03 18:01:38 by malhendi         ###   ########.fr       */
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
	if (!a || !a->mlx)
		return (NULL);
	path = join_asset(name);
	img = mlx_xpm_file_to_image(a->mlx, path, &w, &h);
	if (!img)
	{
		write(2, "Error\nfailed to load image\n", 27);
		close_game(a);
	}
	if (w != TILE || h != TILE)
	{
		write(2, "Error\ninvalid image size\n", 25);
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

void	destroy_images(t_app *a)
{
	if (!a || !a->mlx)
		return ;
	if (a->img.floor)
		mlx_destroy_image(a->mlx, a->img.floor);
	if (a->img.wall)
		mlx_destroy_image(a->mlx, a->img.wall);
	if (a->img.player)
		mlx_destroy_image(a->mlx, a->img.player);
	if (a->img.exit_)
		mlx_destroy_image(a->mlx, a->img.exit_);
	if (a->img.collect)
		mlx_destroy_image(a->mlx, a->img.collect);
	if (a->img.enemy_v)
		mlx_destroy_image(a->mlx, a->img.enemy_v);
	if (a->img.enemy_h)
		mlx_destroy_image(a->mlx, a->img.enemy_h);
	a->img.floor = NULL;
	a->img.wall = NULL;
	a->img.player = NULL;
	a->img.exit_ = NULL;
	a->img.collect = NULL;
	a->img.enemy_v = NULL;
	a->img.enemy_h = NULL;
}
