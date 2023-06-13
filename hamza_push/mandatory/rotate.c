/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:07 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:29:36 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stake **tmp_a)
{
	t_stake	*head;
	t_stake	*led;

	if (!(*tmp_a))
		return ;
	head = *tmp_a;
	*tmp_a = (*tmp_a)->next;
	head->next = NULL;
	led = *tmp_a;
	while (led->next)
		led = led->next;
	led->next = head;
	write(1, "ra\n", 3);
}

void	rb(t_stake **tmp_b)
{
	t_stake	*head;
	t_stake	*led;

	if (!(*tmp_b))
		return ;
	head = *tmp_b;
	*tmp_b = (*tmp_b)->next;
	head->next = NULL;
	led = *tmp_b;
	while (led->next)
		led = led->next;
	led->next = head;
	write(1, "rb\n", 3);
}

void	rr(t_stake **tmp_a, t_stake **tmp_b)
{
	if (!(*tmp_a) || !(*tmp_b))
		return ;
	ra(tmp_a);
	rb(tmp_b);
	write(1, "rr\n", 3);
}
