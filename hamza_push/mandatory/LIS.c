/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:37 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 18:27:35 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lis4(t_stake *Arr, int b)
{
	t_stake	*tmp;
	int		a;

	tmp = Arr;
	while (tmp)
	{
		if (tmp->index == b)
			a = tmp->len;
		tmp = tmp->next;
	}
	free(tmp);
	return (a);
}

t_stake	*lis3(t_stake *Arr, int b)
{
	t_stake	*tmp;
	int		i;
	int		a;

	a = lis4(Arr, b);
	tmp = Arr;
	i = 0;
	while (i < a)
	{
		tmp = Arr;
		while (tmp)
		{
			if (tmp->index == b)
			{
				b = tmp->sub;
				tmp->lis = &i;
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (Arr);
}

int	lis1(t_stake *Arr)
{
	t_stake	*tmp;
	int		b;
	int		a;

	tmp = Arr;
	a = tmp->len;
	while (tmp)
	{
		if (tmp->len >= a)
		{
			a = tmp->len;
			b = tmp->index;
		}
		tmp = tmp->next;
	}
	return (b);
}

t_stake	*lis(char *av[], t_stake *Arr)
{
	t_stake	*tmpi;
	t_stake	*tmpj;
	t_stake	*tmp;
	int		b;

	Arr = creat_stak(av);
	tmpi = Arr->next;
	tmpj = Arr;
	while (tmpi)
	{
		while (tmpj->index < tmpi->index)
		{
			if (tmpj->nbr < tmpi->nbr && tmpj->len + 1 >= tmpi->len)
			{
				tmpi->len = tmpj->len + 1;
				tmpi->sub = tmpj->index;
			}
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
		tmpj = Arr;
	}
	b = lis1(Arr);
	tmp = lis3(Arr, b);
	return (Arr);
}
