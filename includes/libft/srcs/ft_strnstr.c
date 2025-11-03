/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 20:32:23 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/21 23:36:19 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && to_find[j] && i + j < len && str[i
				+ j] == to_find[j])
		{
			j++;
		}
		if (to_find[j] == '\0')
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	*text;
	char	*find;
	char	*res;

	text = "Hello Mohammad";
	find = "Moh";
	res = ft_strnstr(text, find, 10);
	if (res)
		printf("Found: %s\n", res);
	else
		printf("Not found\n");
	return (0);
}
*/
