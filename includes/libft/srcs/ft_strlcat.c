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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	x;
	size_t	z;
	size_t	dl;
	size_t	sl;

	i = 0;
	x = 0;
	while (dest[i] != '\0')
		i++;
	while (src[x] != '\0')
		x++;
	dl = i;
	sl = x;
	if (size == 0 || size <= dl)
		return (size + sl);
	z = 0;
	while (src[z] != '\0' && z < size - dl - 1)
	{
		dest[i] = src[z];
		z++;
		i++;
	}
	dest[i] = '\0';
	return (dl + sl);
}
/*
int	main(void) {
	char dest[] = "mohammad";
	char src[] = "abcdf";

	printf("\n%zu\n", ft_strlcat(dest, src,4));
	char	str1[] = "mohammad";
	char	str2[] = "abcdf";

	size_t size1 = ft_strlcat(str1, str2, 4);
	printf("%s\n %ld\n", str1, size1);

	char	str3[] = "mohammad";
	char	str4[] = "abcdf";

	size_t size2 = ft_strlcat(str3, str4, 4);
	printf("%s\n %ld\n", str3, size2);
	return (0);

}
*/
