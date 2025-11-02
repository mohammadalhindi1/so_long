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
	void	*ary;

	if (nmemb == 0 || size == 0)
	{
		ary = malloc(1);
		if (ary == NULL)
			return (NULL);
		return (ary);
	}
	ary = malloc(nmemb * size);
	if (ary == NULL)
		return (NULL);
	ft_bzero(ary, nmemb * size);
	return (ary);
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
