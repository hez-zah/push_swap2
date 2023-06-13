/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_push_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:41 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:23:29 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_2(t_stake **A)
{
	if ((*A)->nbr > (*A)->next->nbr)
		sa (A);
	exit (0);
}

void	lst_3(t_stake **A)
{
	if ((*A)->next->nbr > (*A)->next->next->nbr && (*A)->index == min_a(A))
	{
		rra(A);
		sa (A);
	}
	if ((*A)->nbr > (*A)->next->nbr && (*A)->next->next->index == max_a(A))
		sa (A);
	else if ((*A)->nbr < (*A)->next->nbr && (*A)->next->next->index == min_a(A))
		rra (A);
	else if ((*A)->next->nbr < (*A)->next->next->nbr && (*A)->index == max_a(A))
		ra(A);
	else if ((*A)->next->nbr > (*A)->next->next->nbr && (*A)->index == max_a(A))
	{
		ra(A);
		sa(A);
	}
}

void	lst_4(t_stake **A, t_stake **B)
{
	int	a;

	a = min_a(A) + 1;
	while (--a && a != 3)
		ra (A);
	if (a == 3)
		rra(A);
	pb(A, B);
	lst_3 (A);
	pa(A, B);
}

void	lst_5(t_stake **A, t_stake **B)
{
	t_stake	*tmp;
	int		i;
	int		j;

	j = 2;
	while (j--)
	{
		tmp = *A;
		while (tmp->index != min_a(A))
			tmp = tmp->next;
		i = tmp->index;
		if (i <= 2)
			while (i--)
				ra(A);
		else
			while (i++ != 5)
				rra(A);
		pb(A, B);
		indx_lst(A, B);
	}
	lst_3 (A);
	pa(A, B);
	pa(A, B);
}

void	min_push_swap(t_stake **A, t_stake **B)
{
	if (size_lst(A) == 2)
		lst_2(A);
	else if (size_lst(A) == 3)
		lst_3(A);
	else if (size_lst(A) == 4)
		lst_4(A, B);
	else if (size_lst(A) == 5)
		lst_5(A, B);
	indx_lst(A, B);
}
