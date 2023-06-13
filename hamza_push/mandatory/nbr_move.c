/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:46 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:24:46 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	len(t_stake **A_B)
{
	t_stake	*new;
	int		len;

	new = *A_B;
	len = 0;
	while (new)
	{
		len++;
		new = new->next;
	}
	return (len);
}

void	search_move_1(t_stake **tmB, t_stake **tmA)
{
	if ((*tmB)->index >= (*tmA)->index)
		(*tmB)->move = (*tmB)->index + 1;
	else
		(*tmB)->move = (*tmA)->index + 1;
}

void	search_move_4(t_stake **tmB, t_stake **tmA)
{
	if ((*tmB)->index >= (*tmA)->index)
		(*tmB)->move = (*tmB)->index + 1;
	else
		(*tmB)->move = (*tmA)->index + 1;
}

void	sous_nbr_move(t_stake **A, t_stake **B, int len_a, int len_b)
{
	t_stake	*tma;
	t_stake	*tmb;

	tmb = *B;
	while (tmb)
	{
		tma = *A;
		while (tma->index != tmb->broth)
			tma = tma->next;
		if (tmb->index <= (len_b / 2) && tma->index <= (len_a / 2))
			search_move_1(&tmb, &tma);
		else if (tmb->index <= (len_b / 2) && tma->index > (len_a / 2))
			tmb->move = tmb->index + (len_a - tma->index) + 1;
		else if (tmb->index > (len_b / 2) && tma->index <= (len_a / 2))
			tmb->move = tma->index + (len_b - tmb->index) + 1;
		else if (tmb->index > (len_b / 2) && tma->index >= (len_a / 2))
			search_move_4(&tmb, &tma);
		tmb = tmb->next;
	}
}

void	nbr_move(t_stake **A, t_stake **B)
{
	int		len_a;
	int		len_b;

	*B = broth_to_b(A, B);
	len_a = len(A);
	len_b = len(B);
	sous_nbr_move(A, B, len_a, len_b);
	class(A, B, len_a, len_b);
	indx_lst(A, B);
}
