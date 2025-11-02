/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:22:45 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/30 19:45:56 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *fmt, ...);

int		ft_putchar_pf(int c);
int		ft_putstr_pf(const char *s);
int		ft_putnbr_pf(int n);
int		ft_putuint_pf(unsigned int n);
int		ft_puthex_pf(unsigned int n, int upper);
int		ft_putptr_pf(const void *ptr);
int		ft_putpercent_pf(void);

int		ft_is_conversion(char c);
int		ft_dispatch(va_list ap, char spec);

int		ft_putnbase_pf(unsigned long long n, const char *base);
size_t	ft_strlen_pf(const char *s);

#endif
