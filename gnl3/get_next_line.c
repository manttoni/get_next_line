/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:14:48 by amaula            #+#    #+#             */
/*   Updated: 2024/05/06 18:00:50 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	d = (unsigned char *) dst;
	s = (const unsigned char *) src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*join(char *s1, size_t s1len, t_nod *ptr)
{
	char			*result;
	unsigned int	i;
	size_t			len;

	len = s1len + ptr->len;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (i < s1len)
			result[i] = s1[i];
		else
			result[i] = ptr->buffer[i - s1len];
		i++;
	}
	if (s1len > 0)
		free(s1);
	return (result);
}

char	*concat(t_nod **list, t_nod *last)
{
	char	*next_line;
	size_t	len;
	t_nod	*ptr;

	if (!last)
		return (NULL);
	len = 0;
	ptr = *list;
	while (ptr != last->next)
	{
		next_line = join(next_line, len, ptr);
		if (next_line == NULL)
		{
			ft_lstclear(list, ft_lstlast(*list));
			return (NULL);
		}
		len += ptr->len;
		ptr = ptr->next;
	}
	if (len == 0)
		return (NULL);
	next_line[len] = '\0';
	ft_lstclear(list, last);
	return (next_line);
}

void	initialize(t_nod **last, char **newlinechr, t_nod *list)
{
	if (!list)
	{
		*newlinechr = NULL;
		*last = NULL;
		return ;
	}
	*last = ft_lstlast(list);
	*newlinechr = ft_memchr((*last)->buffer, '\n', (*last)->len);
}

char	*get_next_line(int fd)
{
	static t_nod	*list;
	t_nod			*last;
	char			buffer[BUFFER_SIZE];
	ssize_t			bytes_read;
	char			*newlinechr;

	if (fd == -1)
		return (NULL);
	initialize(&last, &newlinechr, list);
	while (newlinechr == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			ft_lstclear(&list, ft_lstlast(list));
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		last = newnode(buffer, bytes_read);
		ft_lstadd_back(&list, last);
		newlinechr = ft_memchr(last->buffer, '\n', last->len);
	}
	if (newlinechr && (size_t)(newlinechr + 1 - last->buffer) != last->len)
	{
		ft_lstadd_back(&list, newnode(newlinechr + 1, last->len - (newlinechr + 1 - last->buffer)));
		last->len = newlinechr - last->buffer + 1;
	}
	return (concat(&list, last));
}
