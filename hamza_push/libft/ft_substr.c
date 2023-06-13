/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:39:04 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/10 21:35:52 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_heap1(char *p, const char *led, int start)
{
	int	i;

	i = 0;
	while (led[start] != '\0')
	{
		start++;
		i++;
	}
	p = (char *)malloc((i + 1) * sizeof(char));
	return (p);
}

static char	*ft_heap2(char *p)
{
	p = (char *)malloc(1 * sizeof(char));
	p[0] = '\0';
	return (p);
}

static char	*ft_heap3(char *p, size_t len)
{
	p = (char *)malloc((len + 1) * sizeof(char));
	return (p);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	p = NULL;
	i = 0;
	j = (size_t)start;
	if (start >= ft_strlen(s))
		return (ft_heap2 (p));
	if (len + start >= ft_strlen(s))
		p = ft_heap1 (p, s, start);
	else
		p = ft_heap3 (p, len);
	if (!p)
		return (NULL);
	while (j < (len + (size_t)start) && s[j] != '\0')
	{
		p[i] = s[j];
		i++;
		j++;
	}
	p[i] = '\0';
	return (p);
}
