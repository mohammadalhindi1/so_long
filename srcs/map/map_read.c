/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:13:07 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/03 19:36:49 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	add_line(char ***rows, int *cap, int *h, char *line)
{
	int	len;

	if (!rows || !cap || !h || !line)
		return (0);
	len = trim_newline_len(line);
	if (len == 0)
		return (1);
	if (!rows_reserve(rows, cap, *h + 2, *h))
		return (0);
	(*rows)[*h] = sddup(line, len);
	if (!(*rows)[*h])
		return (0);
	(*h)++;
	return (1);
}

static int	reset_empty(t_rows *r)
{
	if (r->h == 0 || !r->rows || !r->rows[0])
	{
		if (r->rows)
			free_rows_partial(r->rows, r->h);
		r->rows = NULL;
		r->cap = 0;
		r->h = 0;
		return (0);
	}
	return (1);
}

static int	read_loop(int fd, t_rows *r)
{
	char	*line;

	if (!r)
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!add_line(&r->rows, &r->cap, &r->h, line))
		{
			free(line);
			free_rows_partial(r->rows, r->h);
			r->rows = NULL;
			r->cap = 0;
			r->h = 0;
			return (0);
		}
		free(line);
	}
	return (reset_empty(r));
}

static	void	free_gnl(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		free (line);
		line = get_next_line(fd);
	}
}

char	**read_rows(int fd, int *out_h, int *out_w)
{
	t_rows	r;

	if (fd < 0 || !out_h || !out_w)
		return (NULL);
	r.rows = NULL;
	r.cap = 0;
	r.h = 0;
	if (!read_loop(fd, &r))
	{
		free_gnl(fd);
		return (NULL);
	}
	if (!rows_finalize(&r.rows, &r.cap, r.h))
	{
		free_gnl(fd);
		free_rows_partial(r.rows, r.h);
		return (NULL);
	}
	r.rows[r.h] = NULL;
	*out_h = r.h;
	*out_w = (int)ft_strlen(r.rows[0]);
	return (r.rows);
}
