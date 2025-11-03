/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 20:24:49 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/17 20:25:10 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	real_len;
	char	*new_s;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		new_s = (char *)malloc(1);
		if (!new_s)
			return (NULL);
		new_s[0] = '\0';
		return (new_s);
	}
	real_len = slen - start;
	if (real_len > len)
		real_len = len;
	if (real_len > SIZE_MAX - 1)
		return (NULL);
	new_s = (char *)malloc(real_len + 1);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s + start, real_len + 1);
	return (new_s);
}

/*
int	main(void)
{
    char *result;
	char	*result1;

    result = ft_substr("Bonjour comment ca va?", 5, 8);
    printf("Result: %s\n", result);
	result1 = ft_substr("Bonjour comment ca va?", 5, 8);
    printf("Result: %s\n", result1);
    free(result);
	free(result1);
    return (0);
}
*/
