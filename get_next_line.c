#include "get_next_line.h"
#include <stdio.h>

void test()
{
	static int i = 0;
	printf("test: %d\n", i++);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	char		*nl_chr;
	ssize_t		bytes_read;

	next_line = malloc(1);
	if (!next_line)
		return (NULL);
	*next_line = '\0';
	nl_chr = ft_strchr(buffer, '\n');
	while (nl_chr == NULL)
	{
		gnl_join(next_line, buffer, NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0 || !next_line)
			return (NULL);
		if (bytes_read == 0)
		{
			if (*next_line == '\0')
				return (NULL);
			return (next_line);
		}
		nl_chr = ft_strchr(buffer, '\n');
	}
	next_line = gnl_join(next_line, buffer, nl_chr);
	gnl_copy(buffer, nl_chr + 1);
	return (next_line);
}
