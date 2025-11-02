/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 22:08:36 by malhendi          #+#    #+#             */
/*   Updated: 2025/01/06 22:08:45 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= ' ';
	return (c);
}

/*
int	main(void)
{
	int	c;

	c = 'z' ;
	printf("%c",ft_toupper(c));
}
*/
