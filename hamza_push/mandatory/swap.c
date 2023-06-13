/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:15 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:33:19 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stake **tmp_a)
{
	t_stake	*head;
	t_stake	*led;

	if (!(*tmp_a))
		return ;
	head = (*tmp_a)->next;
	if (!head)
		return ;
	(*tmp_a)->next = NULL;
	led = head->next;
	head->next = NULL;
	head->next = *tmp_a;
	(*tmp_a)->next = led;
	*tmp_a = head;
	write(1, "sa\n", 3);
}

void	sb(t_stake **tmp_b)
{
	t_stake	*head;
	t_stake	*led;

	if (!(*tmp_b))
		return ;
	head = (*tmp_b)->next;
	if (!head)
		return ;
	(*tmp_b)->next = NULL;
	led = head->next;
	head->next = NULL;
	head->next = *tmp_b;
	(*tmp_b)->next = led;
	*tmp_b = head;
	write(1, "sb\n", 3);
}

void	ss(t_stake **tmp_a, t_stake **tmp_b)
{
	if (!(*tmp_a) || !(*tmp_b))
		return ;
	sa(tmp_a);
	sb(tmp_b);
	write(1, "ss\n", 3);
}

int	size_lst(t_stake **A)
{
	int		a;
	t_stake	*new;

	new = *A;
	a = 0;
	while (new)
	{
		new = new->next;
		a++;
	}
	return (a);
}
