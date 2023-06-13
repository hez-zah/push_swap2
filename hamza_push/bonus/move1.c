/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:11:43 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/03/18 03:11:58 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	sa(t_stack **tmp_a)
{
	t_stack	*head;
	t_stack	*led;

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
}

void	sb(t_stack **tmp_b)
{
	t_stack	*head;
	t_stack	*led;

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
}

void	ss(t_stack **tmp_a, t_stack **tmp_b)
{
	if (!(*tmp_a) || !(*tmp_b))
		return ;
	sa(tmp_a);
	sb(tmp_b);
}

void	pa(t_stack **tmp_a, t_stack **tmp_b)
{
	t_stack	*head;
	t_stack	*led;

	if (!(*tmp_b))
		return ;
	led = *tmp_a;
	head = *tmp_b;
	*tmp_b = (*tmp_b)->next;
	head->next = led;
	*tmp_a = head;
}

void	pb(t_stack **tmp_a, t_stack **tmp_b)
{
	t_stack	*head;
	t_stack	*led;

	if (!(*tmp_a))
		return ;
	led = *tmp_b;
	head = *tmp_a;
	*tmp_a = (*tmp_a)->next;
	head->next = led;
	*tmp_b = head;
}
