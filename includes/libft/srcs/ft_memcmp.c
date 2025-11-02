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

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
int	main(void)
{
	char	str1[];
	char	str2[];
	int		orig_cmp;
	int		my_cmp;

    str1[] = "Hello";
    str2[] = "Hella";
    orig_cmp = memcmp(str1, str2, 5);
    my_cmp = ft_memcmp(str1, str2, 5);
    printf("Orig_memcmp: %d\n", orig_cmp);
    printf("My ft_memcmp: %d\n", my_cmp);
    return (0);
}
*/
