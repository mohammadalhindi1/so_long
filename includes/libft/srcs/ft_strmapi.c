/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 17:17:56 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/19 17:42:44 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*res;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len > SIZE_MAX - 1)
		return (NULL);
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f((unsigned int)i, s[i]);
		++i;
	}
	res[i] = '\0';
	return (res);
}

/*
int	main(void)
{
	char	*str;
    char *result;

    str = "mohammad alhendi";
    result = ft_strmapi(str, (char (*)(unsigned int, char))ft_toupper);
    if (result)
    {
        printf("Original: %s\n", str);
        printf("Mapped  : %s\n", result);
        free(result);
    }
    else
        printf("Memory allocation failed!\n");
    return (0);
}
*/
