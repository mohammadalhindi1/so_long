/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:36:35 by malhendi          #+#    #+#             */
/*   Updated: 2025/09/01 22:42:29 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_is_conversion(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_dispatch(va_list ap, char spec)
{
	if (spec == 'c')
		return (ft_putchar_pf(va_arg(ap, int)));
	else if (spec == 's')
		return (ft_putstr_pf(va_arg(ap, char *)));
	else if (spec == '%')
		return (ft_putpercent_pf());
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr_pf(va_arg(ap, int)));
	else if (spec == 'u')
		return (ft_putuint_pf(va_arg(ap, unsigned int)));
	else if (spec == 'x')
		return (ft_puthex_pf(va_arg(ap, unsigned int), 0));
	else if (spec == 'X')
		return (ft_puthex_pf(va_arg(ap, unsigned int), 1));
	else if (spec == 'p')
		return (ft_putptr_pf(va_arg(ap, const void *)));
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		total;

	if (fmt == NULL)
		return (-1);
	va_start(ap, fmt);
	total = 0;
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1) && ft_is_conversion(*(fmt + 1)))
		{
			fmt++;
			total += ft_dispatch(ap, *fmt);
		}
		else
			total += (int)write(1, fmt, 1);
		fmt++;
	}
	va_end(ap);
	return (total);
}
