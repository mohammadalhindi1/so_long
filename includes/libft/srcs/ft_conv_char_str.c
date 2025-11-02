/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_char_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:36:47 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/28 17:36:48 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar_pf(int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	return ((int)write(1, &ch, 1));
}

size_t	ft_strlen_pf(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putstr_pf(const char *s)
{
	if (!s)
		return ((int)write(1, "(null)", 6));
	return ((int)write(1, s, ft_strlen_pf(s)));
}

int	ft_putpercent_pf(void)
{
	return ((int)write(1, "%", 1));
}
