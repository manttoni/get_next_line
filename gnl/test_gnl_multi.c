/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:23:57 by amaula            #+#    #+#             */
/*   Updated: 2024/05/03 13:34:47 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd1 = open("test_gnl.txt", O_RDONLY);
	int fd2 = open("test_gnl2.txt", O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		printf("Open fail\n");
		return (1);
	}
	char *line1, *line2;
	while(1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (!line1 && !line2)
			break;
		if (line1)
		{
			printf("file1: %s\n", line1);
			free(line1);
		}
		if (line2)
		{
			printf("file2: %s\n", line2);
			free(line2);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
