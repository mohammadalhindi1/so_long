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
	char	*new;
	size_t	slen;
	size_t	finish;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		new = (char *)malloc(1);
		if (!new)
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	finish = slen - start;
	if (finish > len)
		finish = len;
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
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
