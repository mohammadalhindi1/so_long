/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 02:32:34 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 02:32:35 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_LOADER_H
# define MAP_LOADER_H

typedef struct s_mapinfo
{
	char	**map;
	int		w;
	int		h;
	int		px;
	int		py;
	int		collectibles;
}			t_mapinfo;

t_mapinfo	load_map(const char *path);
void		free_map(char **map);

#endif
