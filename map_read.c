/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:55:22 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 03:55:23 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	trim_newline_len(char *line)
{
	int	len;

	len = slen(line);
	if (len > 0 && line[len - 1] == '\n')
		return (len - 1);
	return (len);
}

static int	grow_rows(char ***rows, int *cap, int need)
{
	char	**tmp;
	int		newcap;

	if (*cap > need)
		return (1);
	newcap = *cap;
	if (newcap == 0)
		newcap = 16;
	else
		newcap = newcap * 2;
	while (newcap <= need)
		newcap *= 2;
	tmp = (char **)realloc(*rows, sizeof(char *) * newcap);
	if (!tmp)
		return (0);
	*rows = tmp;
	*cap = newcap;
	return (1);
}

static int	add_line(char ***rows, int *cap, int *h, char *line)
{
	int	len;

	if (!grow_rows(rows, cap, *h + 2))
		return (0);
	len = trim_newline_len(line);
	(*rows)[*h] = sddup(line, len);
	if (!(*rows)[*h])
		return (0);
	(*h)++;
	return (1);
}

static int	read_loop(int fd, char ***rows, int *cap, int *h)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line(rows, cap, h, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

char	**read_rows(int fd, int *out_h, int *out_w)
{
	char	**rows;
	int		cap;
	int		h;

	rows = NULL;
	cap = 0;
	h = 0;
	if (!read_loop(fd, &rows, &cap, &h) || h == 0)
		return (NULL);
	rows[h] = NULL;
	*out_h = h;
	*out_w = slen(rows[0]);
	return (rows);
}
