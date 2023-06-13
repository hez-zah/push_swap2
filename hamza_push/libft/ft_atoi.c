/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 19:29:46 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 17:08:40 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_nbr(int i, int j, long result, char *led)
{
	if (led[i] == '+' || led[i] == '-')
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (led[i] <= 47 || led[i] >= 58)
		return (0);
	while (led[i] != '\0' && (led[i] >= '0' && led[i] <= '9'))
	{
		result = result + (led[i] - 48);
		result *= 10;
		i++;
	}
	if (led[i] && (led[i] < '0' || led[i] > '9'))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	result /= 10;
	return (result * j);
}

long	ft_atoi(const char *str)
{
	int		i;
	int		j;
	long	result;
	char	*led;

	led = (char *)str;
	i = 0;
	j = 1;
	result = 0;
	while (led[i] == ' ' || led[i] == '\t' || led[i] == '\n'
		|| led[i] == '\v' || led[i] == '\f' || led[i] == '\r')
		i++;
	if (led[i] == '-')
	{
		j *= -1;
		i++;
	}
	else if (led[i] == '+')
		i++;
	return (ft_nbr(i, j, result, led));
}
