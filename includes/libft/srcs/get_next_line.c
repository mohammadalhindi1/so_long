/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malhendi <malhendi@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 16:38:10 by malhendi          #+#    #+#             */
/*   Updated: 2025/11/01 02:36:17 by malhendi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static int	join_into_stash(char **stash, char *buf, ssize_t br)
{
	char	*tmp;

	buf[br] = '\0';
	tmp = ft_strjoin(*stash, buf);
	if (!tmp)
		return (-1);
	free(*stash);
	*stash = tmp;
	return (0);
}

static int	read_to_nl_eof(int fd, char **stash)
{
	char	*buf;
	ssize_t	br;

	if ((size_t)BUFFER_SIZE > SIZE_MAX - 1)
		return (-1);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	br = 0;
	while (!ft_strchr(*stash, '\n'))
	{
		br = read(fd, buf, BUFFER_SIZE);
		if (br <= 0)
			break ;
		if (join_into_stash(stash, buf, br) < 0)
		{
			free(buf);
			return (-1);
		}
	}
	free(buf);
	if (br < 0)
		return (-1);
	return (0);
}

static char	*cut_line(char *stash)
{
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr(stash, 0, i));
}

static void	move_rest(char **stash)
{
	size_t	i;
	char	*rest;

	if (!*stash)
		return ;
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
		i++;
	rest = ft_substr(*stash, i, ft_strlen(*stash + i));
	free(*stash);
	*stash = rest;
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash || read_to_nl_eof(fd, &stash) < 0)
	{
		if (stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	line = cut_line(stash);
	move_rest(&stash);
	if (!line && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
