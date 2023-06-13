/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:12:27 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 03:12:28 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_stack **tmp_a)
{
	t_stack	*head;
	t_stack	*led;

	if (!(*tmp_a))
		return ;
	head = *tmp_a;
	*tmp_a = (*tmp_a)->next;
	head->next = NULL;
	led = *tmp_a;
	while (led->next)
		led = led->next;
	led->next = head;
}

void	rb(t_stack **tmp_b)
{
	t_stack	*head;
	t_stack	*led;

	if (!(*tmp_b))
		return ;
	head = *tmp_b;
	*tmp_b = (*tmp_b)->next;
	head->next = NULL;
	led = *tmp_b;
	while (led->next)
		led = led->next;
	led->next = head;
}

void	rr(t_stack **tmp_a, t_stack **tmp_b)
{
	if (!(*tmp_a) || !(*tmp_b))
		return ;
	ra(tmp_a);
	rb(tmp_b);
}

void	rra(t_stack	**tmp_a)
{
	t_stack	*head;
	t_stack	*led;

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
}

void	rrb(t_stack	**tmp_b)
{
	t_stack	*head;
	t_stack	*led;

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
}
