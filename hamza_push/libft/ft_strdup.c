/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:37:10 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/09 12:44:18 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*mall(char *p)
{
	p = (char *)malloc(1 * sizeof(char));
	if (!p)
		return (NULL);
	p[0] = '\0';
	return (p);
}

char	*ft_strdup(const char *s1)
{
	char	*led1;
	char	*p;
	int		i;

	led1 = (char *)s1;
	p = NULL;
	i = 0;
	if (led1[i] != '\0')
	{
		p = (char *)malloc((ft_strlen(led1) + 1) * sizeof(char));
		if (!p)
			return (NULL);
		while (led1[i] != '\0')
		{
			p[i] = led1[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	else
		return (mall(p));
}
