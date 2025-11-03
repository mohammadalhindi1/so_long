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

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*res;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	if (len > SIZE_MAX - 1)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, src, len + 1);
	return (res);
}

/*
int	main(void)
{
	printf("%s", ft_strdup("hindi"));
	return (0);
}
*/
