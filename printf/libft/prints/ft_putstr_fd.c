/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:24:16 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/14 19:44:11 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd >= 0 && s)
	{
		write(fd, s, ft_strlen(s));
	}
}
