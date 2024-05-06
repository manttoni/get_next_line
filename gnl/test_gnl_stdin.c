/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl_stdin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:17:51 by amaula            #+#    #+#             */
/*   Updated: 2024/05/03 13:22:53 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line;
	while((line = get_next_line(0)) != NULL)
	{
		printf("%s", line);
		free(line);
		scanf("%s", line);
	}
	return 0;
}
