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

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			m;
	unsigned char	*str;

	m = 0;
	str = s;
	while (m < n)
	{
		str[m] = c;
		m++;
	}
	return (s);
}

/*
int	main(void)
{
	char str[] = "mohammad"; 
    char str2[] = "mohammad"; 
    
    memset(str, 'a', 3);
	ft_memset(str2, 'a', 3);
	
	printf("%s\n", str);
	printf("%s\n", str2);
}
*/
