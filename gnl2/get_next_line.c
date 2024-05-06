/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:57:49 by amaula            #+#    #+#             */
/*   Updated: 2024/05/04 17:29:58 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	ssize_t		bytes_read;
	char		*line;
	char		*newline;

	bytes_read = 1;
	line = NULL;
	while (bytes_read > 0)
	{
		newline = ft_strchr(buffer, '\n');
		if (newline)
		{
			line = gnl_strnjoin(line, buffer, newline - buffer + 1);
			ft_strlcpy(buffer, newline + 1, BUFFER_SIZE + 1);
			return (line);
		}
		line = gnl_strnjoin(line, buffer, BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0 || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
