/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 18:42:24 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/11 18:13:27 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	j;

	j = (int)ft_strlen (s);
	while (j >= 0 && s[j] != (unsigned char)c)
		j--;
	if (j == -1)
		return (NULL);
	return ((char *)s + j);
}
