/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:01 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/01 00:32:14 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_LOADER_H
# define MAP_LOADER_H

# include "so_long.h"

t_mapinfo	load_map(const char *path);
void		free_map(char **map);

#endif
