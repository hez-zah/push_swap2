/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:33:21 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/15 10:15:13 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	str = NULL;
	if (count == SIZE_MAX && size == SIZE_MAX)
		return ((void *)str);
	if (count * size == 0)
	{
		str = malloc(1);
		str[0] = '\0';
		return ((void *)str);
	}
	str = malloc((count * size));
	if (!str)
		return (str);
	i = 0;
	while (i < count * size)
	{
		str[i] = '\0';
		i++;
	}
	return ((void *)str);
}
