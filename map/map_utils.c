/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:15 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/01 02:39:44 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	slen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*sddup(const char *s, int n)
{
	char	*p;
	int		i;

	if (!s || n < 0)
		return (NULL);
	p = (char *)malloc((size_t)n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

void	free_rows_partial(char **r, int n)
{
	int	i;

	if (!r || n < 0)
		return ;
	i = 0;
	while (i < n)
	{
		free(r[i]);
		i++;
	}
	free(r);
}

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	copy_rows(char **dst, char **src, int n)
{
	int	i;

	if (!dst || !src || n < 0)
		return (0);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (1);
}
