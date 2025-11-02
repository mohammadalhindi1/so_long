/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:14:03 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/12 18:17:11 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/*
int	main(void)
{
	char	str[];
	char	c;
	char	*res;

	str[] = "mohammad";
	c = 'a';
	res = ft_strrchr(str, c);
	if (res)
		printf("found '%c' at index %ld\n", *res, res - str);
	else
		printf("character '%c' not found\n", c);
	return (0);
}
*/
