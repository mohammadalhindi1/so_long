/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:07 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/02 05:19:41 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	trim_newline_len(char *line)
{
	int	len;

	if (!line)
		return (0);
	len = slen(line);
	while (len > 0 && (line[len - 1] == '\n' || line[len - 1] == '\r'))
		len--;
	return (len);
}

static int	grow_rows(char ***rows, int *cap, int need, int used)
{
	char	**tmp;
	int		newcap;

	if (!rows || !cap || need < 0 || used < 0)
		return (0);
	if (*cap > need)
		return (1);
	newcap = *cap;
	if (newcap <= 0)
		newcap = 16;
	while (newcap <= need)
	{
		if (newcap > 1000000)
			return (0);
		newcap *= 2;
	}
	tmp = (char **)malloc((size_t)newcap * sizeof(char *));
	if (!tmp)
		return (0);
	if (*rows && used > 0)
		copy_rows(tmp, *rows, used);
	free(*rows);
	*rows = tmp;
	*cap = newcap;
	return (1);
}

static int	add_line(char ***rows, int *cap, int *h, char *line)
{
	int	len;

	if (!rows || !cap || !h || !line)
		return (0);
	len = trim_newline_len(line);
	if (len == 0)
		return (1);
	if (!grow_rows(rows, cap, *h + 2, *h))
		return (0);
	(*rows)[*h] = sddup(line, len);
	if (!(*rows)[*h])
		return (0);
	(*h)++;
	return (1);
}

static int	read_loop(int fd, char ***rows, int *cap, int *h)
{
	char	*line;

	if (!rows || !cap || !h)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line(rows, cap, h, line))
		{
			free(line);
			free_rows_partial(*rows, *h);
			*rows = NULL;
			*cap = 0;
			*h = 0;
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
	if (fd < 0 || !out_h || !out_w)
		return (NULL);
	if (!read_loop(fd, &rows, &cap, &h) || h == 0 || !rows || !rows[0])
		return (NULL);
	rows[h] = NULL;
	*out_h = h;
	*out_w = slen(rows[0]);
	return (rows);
}
