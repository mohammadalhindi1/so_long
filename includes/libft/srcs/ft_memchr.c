/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:07:56 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/21 23:40:07 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (((unsigned char *)s) + i);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	const char	str[];
	void		*orig_result;
	void		*my_result;

    str[] = "Hello World";
   
    orig_result = memchr(str, 'o', strlen(str));
    my_result = ft_memchr(str, 'o', strlen(str));
    printf("Orig_memchr: %s\n", (char *)orig_result);
    printf("My ft_memchr: %s\n", (char *)my_result);
    return (0);
}
*/
