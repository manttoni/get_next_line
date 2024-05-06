/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:04:47 by amaula            #+#    #+#             */
/*   Updated: 2024/05/04 18:47:25 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char) c)
			return ((char *) s);
		s++;
	}
	if (*s == '\0' && (char) c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strnjoin(char *s1, const char *s2, size_t len)
{
	char	*new;
	char	*ptr;
	char	*freeable_s1;

	freeable_s1 = s1;
	new = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (new == NULL)
	{
		free(freeable_s1);
		return (NULL);
	}
	ptr = new;
	while (s1 && *s1)
		*ptr++ = *s1++;
	while (s2 && *s2 && len-- > 0)
		*ptr++ = *s2++;
	*ptr = '\0';
	free(freeable_s1);
	return (new);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = gnl_strlen(src);
	i = 0;
	while (i + 1 < dstsize)
	{
		if (i < srclen)
			dst[i] = src[i];
		else
			dst[i] = '\0';
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (gnl_strlen(src));
}

void	ft_bzero(void *s, size_t n)
{
	char	*index;

	index = (char *) s;
	while (n-- > 0)
		*index++ = '\0';
}
