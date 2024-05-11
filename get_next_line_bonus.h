/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaula <amaula@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:40:50 by amaula            #+#    #+#             */
/*   Updated: 2024/05/11 19:09:16 by amaula           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*gnl_join(char *dst, char *src, size_t len);
char	*ft_strchr(char *str, char chr);
void	gnl_copy(char *dst, char *src);
void	ft_bzero(char *buffer, size_t size);

#endif
