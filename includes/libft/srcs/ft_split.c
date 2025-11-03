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

static char	**free_array(char **ptr, size_t filled)
{
	while (filled > 0)
	{
		filled--;
		free(ptr[filled]);
	}
	free(ptr);
	return (NULL);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**split_fill(char const *s, char c, char **out, size_t words)
{
	size_t	i;
	size_t	w;
	size_t	len;

	i = 0;
	w = 0;
	len = 0;
	while (w < words)
	{
		while (s[i] && s[i] == c)
			i++;
		len = 0;
		while (s[i + len] && s[i + len] != c)
			len++;
		out[w] = (char *)malloc(len + 1);
		if (!out[w])
			return (free_array(out, w));
		ft_strlcpy(out[w], s + i, len + 1);
		i = i + len;
		w++;
	}
	out[w] = NULL;
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (words > (SIZE_MAX / sizeof(char *)) - 1)
		return (NULL);
	out = (char **)malloc((words + 1) * sizeof(char *));
	if (!out)
		return (NULL);
	return (split_fill(s, c, out, words));
}

/*
int	main(void)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_split("     hello 42   i am mohammad alhendi ", ' ');
	if (!arr)
		return (1);
	while (arr[i])
	{
		printf("Word[%d]: %s\n", i, arr[i]);
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}
*/
