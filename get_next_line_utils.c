#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_join(char *dst, char *src, char *nl_chr)
{
	char		*ret;
	size_t		len;
	unsigned int	i;

	if (!*src)
		return (dst);
	if (nl_chr == NULL)
		len = ft_strlen(dst) + ft_strlen(src) + 1;
	else
		len = ft_strlen(dst) + (nl_chr - src) + 2;
	ret = malloc(len);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		if (*dst)
			ret[i] = dst[i];
		else
			ret[i] = *src++;
		i++;
	}
	free(dst);
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
