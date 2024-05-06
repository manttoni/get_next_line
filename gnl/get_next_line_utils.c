/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:12:26 by amaula            #+#    #+#             */
/*   Updated: 2024/05/03 13:09:59 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i + 1 < dstsize && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	size_t	size;

	size = ft_strlen(s1) + 1;
	copy = (char *)malloc(size * sizeof(char));
	if (!copy)
		return (NULL);
	ft_strlcpy(copy, s1, size);
	return (copy);
}

void	ft_bzero(void *s, size_t n)
{
	char	*index;

	index = (char *) s;
	while (n-- > 0)
		*index++ = '\0';
}
