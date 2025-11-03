/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:30:00 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/03 05:16:06 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	grow_cap(int cur, int need, int *out)
{
	if (cur <= 0)
		cur = 16;
	while (cur <= need)
	{
		if (cur > 1000000)
			return (0);
		cur *= 2;
	}
	*out = cur;
	return (1);
}

static int	alloc_rows_copy(char ***rows, int used, int newcap)
{
	char	**tmp;
	size_t	bytes;

	if ((size_t)newcap > ((size_t)-1) / sizeof(char *))
		return (0);
	bytes = (size_t)newcap * sizeof(char *);
	tmp = (char **)malloc(bytes);
	if (!tmp)
		return (0);
	if (*rows && used > 0)
		copy_rows(tmp, *rows, used);
	free(*rows);
	*rows = tmp;
	return (1);
}

int	rows_reserve(char ***rows, int *cap, int need, int used)
{
	int	newcap;

	if (!rows || !cap || need < 0 || used < 0)
		return (0);
	if (*cap > need)
		return (1);
	if (!grow_cap(*cap, need, &newcap))
		return (0);
	if (!alloc_rows_copy(rows, used, newcap))
		return (0);
	*cap = newcap;
	return (1);
}

int	rows_finalize(char ***rows, int *cap, int h)
{
	if (!rows || !cap || h < 0)
		return (0);
	if (h + 1 > *cap)
	{
		if (!rows_reserve(rows, cap, h + 1, h))
			return (0);
	}
	return (1);
}
