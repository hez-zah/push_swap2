/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:11 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:30:51 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stake	**tmp_a)
{
	t_stake	*head;
	t_stake	*led;

	head = *tmp_a;
	led = (*tmp_a)->next;
	if (!led || !head)
		return ;
	while (led)
	{
		if (!led->next)
		{
			head->next = NULL;
			led->next = *tmp_a;
			*tmp_a = led;
			break ;
		}
		head = led;
		led = led->next;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_stake	**tmp_b)
{
	t_stake	*head;
	t_stake	*led;

	head = *tmp_b;
	led = (*tmp_b)->next;
	if (!led || !(*tmp_b))
		return ;
	while (led)
	{
		if (!led->next)
		{
			head->next = NULL;
			led->next = *tmp_b;
			*tmp_b = led;
			break ;
		}
		head = led;
		led = led->next;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_stake **tmp_a, t_stake **tmp_b)
{
	if (!(*tmp_a) || !(*tmp_b))
		return ;
	rra(tmp_a);
	rrb(tmp_b);
	write(1, "rrr\n", 4);
}
