/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 16:48:12 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/12 17:51:20 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
/*
int	main(void)
{
	char str1[] = " ---+--+1234ab567";
	char str2[] = "   ++42";
	char str3[] = "  -00123";
	char str4[] = "56789abc";
	char str5[] = "   ---+++";

	printf("%d\n", ft_atoi(str1)); 
	printf("%d\n", ft_atoi(str2)); 
	printf("%d\n", ft_atoi(str3)); 
	printf("%d\n", ft_atoi(str4)); 
	printf("%d\n", ft_atoi(str5)); 
	return (0);
}*/
