/* ************************************************************************** */
/*			                                                                */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:11:41 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/10/29 23:12:12 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*m;

	if (!s || !f)
		return (NULL);
	m = (char *)malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!m)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		*(m + i) = (*f)(i, *(s + i));
		i++;
	}
	*(m + i) = '\0';
	return (m);
}
