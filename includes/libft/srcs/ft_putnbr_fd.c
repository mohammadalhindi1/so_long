/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:07:56 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/12 18:14:37 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	putnbr_positive_fd(int n, int fd)
{
	char	dgt;

	if (n > 9)
	{
		putnbr_positive_fd(n / 10, fd);
		putnbr_positive_fd(n % 10, fd);
	}
	else
	{
		dgt = n + '0';
		write(fd, &dgt, 1);
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (fd == -1)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	putnbr_positive_fd(n, fd);
}

/*
int	main(void)
{
    ft_putnbr_fd(42, 1);       
    write(1, "\n", 1);
    ft_putnbr_fd(-12345, 1);   
    write(1, "\n", 1);
    ft_putnbr_fd(0, 1);         
    ft_putnbr_fd(-2147483648, 1); 
    write(1, "\n", 1);
    return (0);
}
*/
