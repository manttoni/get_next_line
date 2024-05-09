#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s && *s++)
		len++;
	return (len);
}

char	*gnl_join(char *dst, char *src, size_t len)
{
	char		*ret;
	char		*ptr;
	size_t		bytes;
	unsigned int	i;

	if (!*src)
		return (dst);
	bytes = ft_strlen(dst) + len + 1;
	ret = malloc(bytes);
	if (ret == NULL)
	{
		free(dst);
		return (NULL);
	}
	i = 0;
	ptr = dst;
	while (i < bytes - 1)
	{
		if (*dst)
			ret[i] = *dst++;
		else
			ret[i] = *src++;
		i++;
	}
	free(ptr);
	ret[i] = '\0';
	return (ret);
}

void	gnl_copy(char *dst, char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
}

char	*ft_strchr(char *str, char chr)
{
	while (*str)
	{
		if (*str == chr)
			return (str);
		str++;
	}
	return (NULL);
}

void	ft_bzero(char *buffer, size_t size)
{
	while (size-- > 0)
		buffer[size] = '\0';
}
