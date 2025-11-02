/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_linux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:11:30 by malhendi          #+#    #+#             */
/*   Updated: 2025/10/30 23:11:33 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_display(t_app *a)
{
	if (a && a->mlx)
	{
		mlx_destroy_display(a->mlx);
		free(a->mlx);
		a->mlx = NULL;
	}
}
