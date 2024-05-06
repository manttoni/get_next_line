/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:40:50 by amaula            #+#    #+#             */
/*   Updated: 2024/05/06 17:59:45 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct n
{
	char		*buffer;
	size_t		len;
	struct n	*next;
}	t_nod;

char	*get_next_line(int fd);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*join(char *s1, size_t s1len, t_nod *ptr);
char	*concat(t_nod **list, t_nod *last);
void	initialize(t_nod **last, char **newlinechr, t_nod *list);
t_nod	*newnode(char *data, size_t len);
t_nod	*ft_lstlast(t_nod *list);
void	ft_lstadd_back(t_nod **list, t_nod *new);
void	ft_lstclear(t_nod **list, t_nod *last);

#endif
