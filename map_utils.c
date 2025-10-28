/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 03:24:36 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/28 03:24:37 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	slen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*sddup(const char *s, int n)
{
	char	*p;
	int		i;

	p = (char *)malloc(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

void	free_rows_partial(char **r, int n)
{
	int	i;

	i = 0;
	if (!r)
		return ;
	while (i < n)
	{
		free(r[i]);
		i++;
	}
	free(r);
}

void	free_map(char **m)
{
	int	i;

	i = 0;
	if (!m)
		return ;
	while (m[i])
	{
		free(m[i]);
		i++;
	}
	free(m);
}
