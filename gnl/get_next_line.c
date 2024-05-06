/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:00:17 by amaula            #+#    #+#             */
/*   Updated: 2024/05/03 13:54:18 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			line[BUFFER_SIZE];
	char			bufchr;
	ssize_t			bytes_read;
	unsigned int	i;

	ft_bzero(line, BUFFER_SIZE);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		bytes_read = read(fd, &bufchr, 1);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
			break ;
		line[i++] = bufchr;
		if (bufchr == '\n')
			break ;
	}
	if (i >= BUFFER_SIZE || i == 0)
		return (NULL);
	return (ft_strdup(line));
}
