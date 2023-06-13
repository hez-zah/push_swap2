/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:09:46 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 18:01:01 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

t_stack	*lst_new(char *content)
{
	t_stack	*new;

	new = NULL;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nbr = ft_atoi(content);
	new->next = NULL;
	return (new);
}

t_stack	*lst_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	lst_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = *lst;
		last = lst_last(last);
		last->next = new;
	}
}

void	rrr(t_stack **tmp_a, t_stack **tmp_b)
{
	if (!(*tmp_a) || !(*tmp_b))
		return ;
	rra(tmp_a);
	rrb(tmp_b);
}

int	class_result(t_stack **stack_a)
{
	t_stack	*new;

	new = *stack_a;
	while (new->next)
	{
		if (new->nbr > new->next->nbr)
			return (0);
		new = new->next;
	}
	return (1);
}
