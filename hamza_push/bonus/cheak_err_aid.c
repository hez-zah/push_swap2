/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_err_aid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:37:56 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 17:22:31 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

int	stack_aid_error(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (av[++i])
	{
		j = -1;
		if (!av[i][0])
			return (0);
		while (av[i][++j])
		{
			if (av[i][j] == ' ')
				k++;
			else
			{
				k = 0;
				break ;
			}
		}
		if (k)
			return (0);
	}
	return (1);
}
