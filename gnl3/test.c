/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:27:56 by amaula            #+#    #+#             */
/*   Updated: 2024/05/04 18:51:54 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Open failed\n");
		return 1;
	}
	char	*line;
	while ((line = get_next_line(fd)) > 0)
	{
		printf("Next_line = %s", line);
		free(line);
	}
	close(fd);
	return 0;
}
