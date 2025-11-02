/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:36:41 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/30 17:19:25 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbase_pf(unsigned long long n, const char *base)
{
	int	b;
	int	count;

	b = 0;
	count = 0;
	while (base[b])
		b++;
	if (b < 2)
		return (0);
	if (n >= (unsigned long long)b)
		count += ft_putnbase_pf(n / b, base);
	count += (int)write(1, &base[n % b], 1);
	return (count);
}

int	ft_putnbr_pf(int n)
{
	char	d;
	int		c;

	c = 0;
	if (n == -2147483648)
		return ((int)write(1, "-2147483648", 11));
	if (n < 0)
	{
		c += (int)write(1, "-", 1);
		n = -n;
	}
	if (n > 9)
		c += ft_putnbr_pf(n / 10);
	d = (char)('0' + (n % 10));
	return (c + (int)write(1, &d, 1));
}

int	ft_putuint_pf(unsigned int n)
{
	char	d;
	int		c;

	c = 0;
	if (n > 9)
		c += ft_putuint_pf(n / 10);
	d = (char)('0' + (n % 10));
	return (c + (int)write(1, &d, 1));
}

int	ft_puthex_pf(unsigned int n, int upper)
{
	const char	*base;

	if (upper)
		base = HEX_UPPER;
	else
		base = HEX_LOWER;
	return (ft_putnbase_pf((unsigned long long)n, base));
}

int	ft_putptr_pf(const void *p)
{
	unsigned long long	addr;
	int					count;

	if (!p)
		return ((int)write(1, "(nil)", 5));
	count = (int)write(1, "0x", 2);
	addr = (unsigned long long)p;
	count += ft_putnbase_pf(addr, HEX_LOWER);
	return (count);
}
