/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:14:25 by amaula            #+#    #+#             */
/*   Updated: 2024/05/06 17:59:43 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_nod	*newnode(char *data, size_t len)
{
	static t_nod	*new;

	new = malloc(sizeof(t_nod));
	if (!new)
		return (NULL);
	new->buffer = malloc(len);
	ft_memcpy(new->buffer, data, len);
	new->len = len;
	new->next = NULL;
	return (new);
}

t_nod	*ft_lstlast(t_nod *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

void	ft_lstadd_back(t_nod **list, t_nod *new)
{
	if (!*list)
	{
		*list = new;
		return ;
	}
	ft_lstlast(*list)->next = new;
}

void	ft_lstclear(t_nod **list, t_nod *last)
{
	t_nod	*next;
	t_nod	*curr;

	if (!*list)
		return ;
	curr = *list;
	*list = last->next;
	while (curr)
	{
		next = curr->next;
		if (curr == *list)
			break ;
		free(curr->buffer);
		free(curr);
		curr = next;
	}
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*uc;

	uc = (unsigned char *) s;
	while (n-- > 0)
	{
		if (*uc == (unsigned char) c)
			return ((void *) uc);
		uc++;
	}
	return (NULL);
}
