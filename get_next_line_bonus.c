/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 12:40:51 by amaula            #+#    #+#             */
/*   Updated: 2024/05/11 16:53:36 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	init(char **next_line, char **nl_chr, char *buffer, int fd)
{
	if (fd < 0 || fd >= MAX_FD)
		return (0);
	*next_line = malloc(1);
	if (*next_line == NULL)
		return (0);
	**next_line = '\0';
	*nl_chr = ft_strchr(buffer, '\n');
	return (1);
}

static int	read_to_buffer(int fd, char *buffer, char **next_line)
{
	ssize_t	bytes_read;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(*next_line);
		return (-1);
	}
	if (bytes_read == 0)
	{
		if (**next_line == '\0')
		{
			free(*next_line);
			return (-1);
		}
		return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	buffer[MAX_FD][BUFFER_SIZE + 1];
	char		*next_line;
	char		*nl_chr;
	int			read_result;

	if (init(&next_line, &nl_chr, buffer[fd], fd) == 0)
		return (NULL);
	while (nl_chr == NULL)
	{
		next_line = gnl_join(next_line, buffer[fd], ft_strlen(buffer[fd]));
		if (!next_line)
			return (NULL);
		read_result = read_to_buffer(fd, buffer[fd], &next_line);
		if (read_result == -1)
			return (NULL);
		if (read_result == 0)
			return (next_line);
		nl_chr = ft_strchr(buffer[fd], '\n');
	}
	next_line = gnl_join(next_line, buffer[fd], (nl_chr - buffer[fd]) + 1);
	if (!next_line)
		return (NULL);
	gnl_copy(buffer[fd], nl_chr + 1);
	return (next_line);
}
