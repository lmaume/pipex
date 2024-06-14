/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:01:42 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/04 16:11:38 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../printf/libft/libft.h"

size_t	ft_linelen(const char *str);
char	*get_next_line(int fd);
char	*ft_strldup(char *s, size_t len);
char	*ft_strljoin(char *s1, char *s2, size_t len);
void	*ft_memmcpy(void *dest, void *src, size_t n);

#endif
