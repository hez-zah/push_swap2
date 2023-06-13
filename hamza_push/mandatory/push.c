/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:03 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:28:38 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stake **tmp_a, t_stake **tmp_b)
{
	t_stake	*head;
	t_stake	*led;

	if (!(*tmp_b))
		return ;
	led = *tmp_a;
	head = *tmp_b;
	*tmp_b = (*tmp_b)->next;
	head->next = led;
	*tmp_a = head;
	write(1, "pa\n", 3);
}

void	pb(t_stake **tmp_a, t_stake **tmp_b)
{
	t_stake	*head;
	t_stake	*led;

	if (!(*tmp_a))
		return ;
	led = *tmp_b;
	head = *tmp_a;
	*tmp_a = (*tmp_a)->next;
	head->next = led;
	*tmp_b = head;
	write(1, "pb\n", 3);
}

int	comme_true(t_stake **A)
{
	t_stake	*tmp;

	tmp = *A;
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
