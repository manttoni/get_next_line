/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:20:53 by amaula            #+#    #+#             */
/*   Updated: 2024/05/02 16:09:12 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "get_next_line.h"

int main(void)
{
	int		fd;
	char	*file;
	char	*line;

	file = "test_gnl.txt";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Open fail\n");
		return (1);
	}
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			printf("Read fail or nothing more to read\n");
			return (1);
		}
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
