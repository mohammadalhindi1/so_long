/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 02:20:11 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/01 02:40:36 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	**clone_map(char **r, int h)
{
	char	**c;
	int		y;

	if (!r || h <= 0)
		return (NULL);
	c = (char **)malloc(sizeof(char *) * (size_t)(h + 1));
	if (!c)
		return (NULL);
	y = 0;
	while (y < h)
	{
		c[y] = sddup(r[y], slen(r[y]));
		if (!c[y])
		{
			free_rows_partial(c, y);
			return (NULL);
		}
		y++;
	}
	c[h] = NULL;
	return (c);
}

static void	ff(t_ff *ctx, int y, int x)
{
	if (!ctx || !ctx->m || ctx->h <= 0 || ctx->w <= 0)
		return ;
	if (y < 0 || x < 0 || y >= ctx->h || x >= ctx->w)
		return ;
	if (ctx->m[y][x] == '1' || ctx->m[y][x] == 'X')
		return ;
	if (ctx->m[y][x] == 'C')
		ctx->got_c++;
	if (ctx->m[y][x] == 'E')
		ctx->hit_e = 1;
	ctx->m[y][x] = 'X';
	ff(ctx, y + 1, x);
	ff(ctx, y - 1, x);
	ff(ctx, y, x + 1);
	ff(ctx, y, x - 1);
}

int	validate_paths(char **r, int h, int w, t_mapinfo o)
{
	t_ff	ctx;

	if (!r || h <= 0 || w <= 0)
		return (0);
	if (o.px < 0 || o.py < 0 || o.px >= w || o.py >= h)
		return (0);
	ctx.m = clone_map(r, h);
	if (!ctx.m)
		return (0);
	ctx.h = h;
	ctx.w = w;
	ctx.got_c = 0;
	ctx.hit_e = 0;
	ff(&ctx, o.py, o.px);
	free_map(ctx.m);
	if (ctx.got_c != o.collects || !ctx.hit_e)
		return (0);
	return (1);
}
