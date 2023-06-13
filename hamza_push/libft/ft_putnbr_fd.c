/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:23:29 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/09 15:20:01 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putchar_fd (8 + '0', fd);
	}
	else if (n >= 0 && n < 10)
		ft_putchar_fd (n + '0', fd);
	else if (n >= 10)
	{
		ft_putnbr_fd (n / 10, fd);
		ft_putnbr_fd (n % 10, fd);
	}
	else
	{
		ft_putchar_fd ('-', fd);
		ft_putnbr_fd (-1 * n, fd);
	}
}
