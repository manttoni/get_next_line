/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 12:06:12 by amaula            #+#    #+#             */
/*   Updated: 2024/05/04 17:24:12 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strnjoin(char *s1, const char *s2, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_bzero(void *s, size_t n);


#endif
