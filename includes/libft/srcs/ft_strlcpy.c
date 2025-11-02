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

//#include <string.h>
//#include <bsd/bsd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

/*
int	main(void)
{
	char	str1[];
	char	str2[];
	size_t	size1;
	char	str3[];
	char	str4[];
	size_t	size2;

	str1[] = "mohammad";
	str2[] = "abcdf";
	size1 = strlcpy(str1, str2, 1);
	printf("%s\n %ld\n", str1, size1);
	str3[] = "mohammad";
	str4[] = "abcdf";
	size2 = ft_strlcpy(str3, str4, 1);
	printf("%s\n %ld\n", str3, size2);
	return (0);
}
*/
