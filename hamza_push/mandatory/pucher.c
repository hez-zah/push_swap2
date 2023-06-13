/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pucher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:56 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:26:26 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	boucl(t_stake *A)
{
	t_stake	*new;

	new = A;
	while (new)
	{
		if (!new->lis)
			return (0);
		new = new->next;
	}
	return (1);
}

int	nbr(t_stake *ret, t_stake *led, int i)
{
	int		k;
	int		j;

	j = 0;
	k = -1;
	while (++k < i)
	{
		led = ret;
		while (led)
		{
			if (led->lis && !led->next && !k)
			{
				led->test = 1;
				j++;
			}
			else if (led->lis && led->next && led->next->test == 1)
			{
				led->test = 1;
				led->next->test = 0;
				j++;
			}
			led = led->next;
		}
	}
	return (j);
}

int	rra_cheak(t_stake *A)
{
	t_stake	*tmp;
	t_stake	*ret;
	t_stake	*led;
	int		i;
	int		j;

	tmp = A;
	ret = A;
	led = NULL;
	i = 0;
	while (ret)
	{
		if (!ret->lis)
			break ;
		ret = ret->next;
		i++;
	}
	j = nbr(ret, led, i);
	if (i - j >= 2)
		return (1);
	return (0);
}

void	pucher(t_stake **A, t_stake **B)
{
	t_stake	*tmp;
	int		i;

	*B = NULL;
	tmp = *A;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	while (!boucl(*A))
	{
		if (!(*A)->lis)
			pb(A, B);
		else if (rra_cheak(*A))
			rra(A);
		else if ((*A)->lis && !(*A)->next->lis && (*A)->index != i - 1)
			ra(A);
		else if ((*A)->next && (*A)->index != i - 1)
			ra(A);
	}
	indx_lst(A, B);
}
