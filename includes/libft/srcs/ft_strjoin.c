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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_string;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len2 > SIZE_MAX - len1 - 1)
		return (NULL);
	new_string = (char *)malloc(len1 + len2 + 1);
	if (!new_string)
		return (NULL);
	ft_strlcpy(new_string, s1, len1 + 1);
	ft_strlcat(new_string, s2, len1 + len2 + 1);
	return (new_string);
}

/*
int	main(void)
{
	char	*s1;
	char	*s2;
    char *result;
	char	*result2;

    s1 = "Hello,";
    s2 = " World!";
    result = ft_strjoin(s1, s2);
	result2 = ft_strjoin(s1, s2);
    if (result == NULL)
    {
        printf("Error: Memory allocation failed.\n");
        return (1);
    }
    printf("Joined string: %s\n", result); 
	printf("Joined string: %s\n", result2);
	free(result); 
    free(result2); 
    return (0);
}
*/
