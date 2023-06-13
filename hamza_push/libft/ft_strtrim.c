/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:03:51 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/11 11:48:12 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_first(char const *led, char const *sup, size_t j, size_t i)
{
	int	t;

	t = 1;
	while (led[i] != '\0')
	{
		j = 0;
		while (sup[j] != '\0')
		{
			if (led[i] == sup[j])
			{
				t = 0;
				break ;
			}
			t = 1;
			j++;
		}
		if (t == 1)
			break ;
		i++;
	}
	return (i);
}

static int	ft_last(char const *led, char const *sup, size_t j, int k)
{
	int	t;

	t = 1;
	while (j >= 0)
	{
		k = ft_strlen (sup) - 1;
		while (k >= 0)
		{
			if (led[j] == sup[k])
			{
				t = 0;
				break ;
			}
			t = 1;
			k--;
		}
		if (t == 1)
			break ;
		j--;
	}
	return (j);
}

static char	*ft_str1(char const *s1, size_t i, size_t j)
{
	int		t;
	char	*p;

	p = (char *)malloc((j - i + 2) * sizeof(char));
	if (!p)
		return (NULL);
	t = 0;
	while (i <= j)
	{
		p[t] = s1[i];
		t++;
		i++;
	}
	p[t] = '\0';
	return (p);
}

static char	*ft_str2(char *p)
{
	p = (char *)malloc(1 * sizeof(char));
	if (!p)
		return (p);
	p[0] = '\0';
	return (p);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	int		t;
	int		k;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	k = 0;
	p = NULL;
	i = 0;
	t = 1;
	i = ft_first (s1, set, j, i);
	j = ft_strlen (s1) - 1 ;
	t = 1;
	j = ft_last (s1, set, j, k);
	if (i != ft_strlen (s1))
		return (ft_str1 (s1, i, j));
	else
		return (ft_str2 (p));
}
