/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:38:13 by malhendi          #+#    #+#             */
/*   Updated: 2025/09/05 17:57:07 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	dup = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	char	*p;
	size_t	i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	res = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
		return (NULL);
	p = res;
	i = 0;
	while (s1[i])
		*p++ = s1[i++];
	i = 0;
	while (s2[i])
		*p++ = s2[i++];
	*p = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	take;
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		take = 0;
	else if (slen - start > len)
		take = len;
	else
		take = slen - start;
	new = (char *)malloc(take + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (i < take)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
