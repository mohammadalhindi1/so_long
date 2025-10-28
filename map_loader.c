/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:24:30 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 03:24:31 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mapinfo	load_map(const char *path)
{
	t_mapinfo	i;
	char		**r;
	int			fd;
	int			h;
	int			w;

	i.map = NULL;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		fprintf(stderr, "Error\ncannot open: %s\n", path);
		return (i);
	}
	r = read_rows(fd, &h, &w);
	close(fd);
	if (!r || !validate_map(r, h, w, &i))
	{
		fprintf(stderr, "Error\nbad map\n");
		free_map(r);
		return (i);
	}
	i.w = w;
	i.h = h;
	i.map = r;
	return (i);
}
