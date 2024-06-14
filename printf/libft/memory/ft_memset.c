/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaume <lmaume@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 21:15:16 by lmaume            #+#    #+#             */
/*   Updated: 2024/06/14 19:43:45 by lmaume           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (s);
	while (i <= n - 1)
	{
		((char *)s)[i] = (char)c;
		i++;
	}
	return (s);
}
