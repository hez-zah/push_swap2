/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   class.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:26 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 18:17:04 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_1(t_stake **tmB1, t_stake **tmA, t_stake **A, t_stake **B)
{
	int	i;
	int	j;

	i = (*tmB1)->index;
	j = (*tmA)->index;
	if ((*tmB1)->index <= (*tmA)->index)
	{
		i = (*tmB1)->index + 1;
		j = (*tmA)->index - (*tmB1)->index + 1;
		while (--i)
			rr(A, B);
		while (--j)
			ra(A);
	}
	else
	{
		i = (*tmA)->index + 1;
		j = (*tmB1)->index - (*tmA)->index + 1;
		while (--i)
			rr(A, B);
		while (--j)
			rb(B);
	}
	pa(A, B);
}

void	move_2(t_stake **tmB1, t_stake **tmA, t_stake **A, t_stake **B)
{
	int	i;
	int	j;

	i = len(A) - (*tmA)->index + 1;
	j = (*tmB1)->index + 1;
	while (--i)
		rra(A);
	while (--j)
		rb(B);
	pa(A, B);
}

void	move_3(t_stake **tmB1, t_stake **tmA, t_stake **A, t_stake **B)
{
	int	i;
	int	j;

	i = len(B) - (*tmB1)->index + 1;
	j = (*tmA)->index + 1;
	while (--i)
		rrb(B);
	while (--j)
		ra(A);
	pa(A, B);
}

void	move_4(t_stake **tmB1, t_stake **tmA, t_stake **A, t_stake **B)
{
	int	i;
	int	j;

	if ((len(B) - (*tmB1)->index) <= (len(A) - (*tmA)->index))
	{
		i = len(B) - (*tmB1)->index + 1;
		j = (len(A) - (*tmA)->index) - (len(B) - (*tmB1)->index) + 1;
		while (--i)
			rrr(A, B);
		while (--j)
			ra(A);
	}
	else
	{
		i = (len(A) - (*tmA)->index) + 1;
		j = (len(B) - (*tmB1)->index) - (len(A) - (*tmA)->index) + 1;
		while (--i)
			rrr(A, B);
		while (--j)
			rb(A);
	}
	pa(A, B);
}

void	class(t_stake **A, t_stake **B, int len_a, int len_b)
{
	t_stake	*tma;
	t_stake	*tmb1;
	t_stake	*tmb2;

	tmb1 = *B;
	tmb2 = *B;
	tma = *A;
	while (tmb2)
	{
		if (tmb2->move <= tmb1->move)
			tmb1 = tmb2;
		tmb2 = tmb2->next;
	}
	while (tma->index != tmb1->broth)
		tma = tma->next;
	if (tmb1->index <= (len_b / 2) && tma->index <= (len_a / 2))
		move_1(&tmb1, &tma, A, B);
	else if (tmb1->index <= (len_b / 2) && tma->index > (len_a / 2))
		move_2(&tmb1, &tma, A, B);
	else if (tmb1->index > (len_b / 2) && tma->index <= (len_a / 2))
		move_3(&tmb1, &tma, A, B);
	else if (tmb1->index > (len_b / 2) && tma->index >= (len_a / 2))
		move_4(&tmb1, &tma, A, B);
}
