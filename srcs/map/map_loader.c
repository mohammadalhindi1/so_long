/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:12:54 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/02 05:12:31 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	check_ext_and_open(const char *path, t_mapinfo *i, int *fd)
{
	char	*ext;
	int		len;

	*i = init_mapinfo();
	ext = ft_strrchr(path, '.');
	if (!ext)
		return (0);
	len = ft_strlen(ext);
	if (len != 4)
		return (0);
	if (ft_strncmp(ext, ".ber", 4))
		return (0);
	*fd = open_map_fd(path);
	return (1);
}

t_mapinfo	load_map(const char *path)
{
	t_mapinfo	i;
	char		**r;
	int			fd;
	int			h;
	int			w;

	if (!check_ext_and_open(path, &i, &fd))
	{
		ft_printf("ERRRRROOOOOOOOOOOOOR");
		return (i);
	}
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
