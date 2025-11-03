/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:23:23 by malhendi          #+#    #+#             */
/*   Updated: 2025/08/21 23:41:17 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	out_len;
	char	*new_s;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_in_set(s1[end - 1], set))
		end--;
	out_len = end - start;
	if (out_len > SIZE_MAX - 1)
		return (NULL);
	new_s = (char *)malloc(out_len + 1);
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1 + start, out_len + 1);
	return (new_s);
}

/*
int	main(void)
{
	char	*s;
	char	*set;
    char *trimmed;

    s = "   Hello World!!!  ";
    set = " !";
    trimmed = ft_strtrim(s, set);
    if (!trimmed)
    {
        printf("Error: Memory allocation failed.\n");
        return (1);
    }
    printf("Trimmed string: '%s'\n", trimmed);
    free(trimmed);
    return (0);
}
*/
