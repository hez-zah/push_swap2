/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broth_to_B.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:04 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 18:13:06 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	max_a(t_stake **A)
{
	t_stake	*new;
	int		a;
	int		b;

	new = *A;
	a = new->index;
	b = new->nbr;
	while (new->next)
	{
		if (new->next->nbr > b)
		{
			b = new->next->nbr;
			a = new->next->index;
		}
		new = new->next;
	}
	return (a);
}

int	min_a(t_stake **A)
{
	t_stake	*new;
	int		a;
	int		b;

	new = *A;
	a = new->index;
	b = new->nbr;
	while (new->next)
	{
		if (new->next->nbr < b)
		{
			b = new->next->nbr;
			a = new->next->index;
		}
		new = new->next;
	}
	return (a);
}

int	nbr_brother(t_stake **A, t_stake **B)
{
	t_stake	*pos;

	pos = *A;
	while (pos->next)
	{
		if (pos->nbr < (*B)->nbr && pos->next->nbr > (*B)->nbr)
			return (pos->next->index);
		pos = pos->next;
	}
	if (pos->nbr < (*B)->nbr && (*A)->nbr > (*B)->nbr)
		return ((*A)->index);
	return (min_a(A));
}

t_stake	*broth_to_b(t_stake **A, t_stake **B)
{
	t_stake	*pos;

	pos = *B;
	while (pos)
	{
		pos->broth = nbr_brother(A, &pos);
		pos = pos->next;
	}
	return (*B);
}

int	stack_aid_error(char **av)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (av[++i])
	{
		j = -1;
		if (!av[i][0])
			return (0);
		while (av[i][++j])
		{
			if (av[i][j] == ' ')
				k++;
			else
			{
				k = 0;
				break ;
			}
		}
		if (k)
			return (0);
	}
	return (1);
}
