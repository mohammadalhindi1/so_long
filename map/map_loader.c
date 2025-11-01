/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:12:54 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/01 00:45:03 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static t_mapinfo	init_mapinfo(void)
{
	t_mapinfo	i;

	i.map = NULL;
	i.w = 0;
	i.h = 0;
	i.px = 0;
	i.py = 0;
	i.collects = 0;
	return (i);
}

static int	open_map_fd(const char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		write(2, "Error\ncannot open\n", 18);
	return (fd);
}

t_mapinfo	load_map(const char *path)
{
	t_mapinfo	i;
	char		**r;
	int			fd;
	int			h;
	int			w;

	i = init_mapinfo();
	fd = open_map_fd(path);
	if (fd < 0)
		return (i);
	r = read_rows(fd, &h, &w);
	close(fd);
	if (!r || !validate_map(r, h, w, &i))
	{
		write(2, "Error\nbad map\n", 14);
		free_map(r);
		return (i);
	}
	i.w = w;
	i.h = h;
	i.map = r;
	return (i);
}
