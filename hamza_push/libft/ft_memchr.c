/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:00:16 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/10 19:29:16 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*led;
	size_t			i;

	led = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	else
	{
		i = 0;
		while (i < n)
		{
			if (led[i] == (unsigned char)c)
				return (led + i);
			i++;
		}
		return (NULL);
	}
}
