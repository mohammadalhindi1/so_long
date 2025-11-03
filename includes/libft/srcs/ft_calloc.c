/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 23:07:56 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/02 05:13:32 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
int	main(void)
{
    int *arr;
	size_t	n;
    size_t i;

    n = 5;
    arr = ft_calloc(n, sizeof(int)); 
    if (!arr)
    {
        printf("malloc failed\n");
        return (1);
    }
    printf("ft_calloc:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    free(arr);
    return (0);
}
*/
