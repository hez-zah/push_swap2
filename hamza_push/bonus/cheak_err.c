/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheak_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:00:32 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 18:12:02 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	free_ret(char **ret)
{
	int	i;

	i = -1;
	while (ret[++i])
		free(ret[i]);
	free(ret[i]);
}

int	cheak_err(char *av[])
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		while (av[i][++j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && \
				(av[i][j] != ' ' && av[i][j] != '-'))
				return (0);
		}
	}
	return (1);
}

void	ind_stack(t_stack	**stack_a)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
	while (tmp)
	{
		tmp->indx = i;
		i++;
		tmp = tmp->next;
	}
}

int	cheak_err_doubl(t_stack **A)
{
	t_stack	*new;
	t_stack	*old;

	old = *A;
	while (old->next)
	{
		new = *A;
		while (new)
		{
			if (new->nbr == old->nbr && new->indx != old->indx)
				return (0);
			new = new->next;
		}
		old = old->next;
	}
	return (1);
}

void	fill_stack_a(char *av[], t_stack **stack_a)
{
	t_stack	*new;
	char	**ret;
	int		i;
	int		j;

	i = 0;
	while (av[++i])
	{
		ret = ft_split(av[i], ' ');
		j = -1;
		while (ret[++j])
		{
			new = lst_new(ret[j]);
			lst_add_back(stack_a, new);
		}
		free_ret(ret);
		ind_stack(stack_a);
	}
	if (!cheak_err_doubl(stack_a))
	{
		write(1, "Error", 5);
		exit (1);
	}
}
