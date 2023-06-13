/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:02:45 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 17:20:03 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"
#include "g_n_l/get_next_line.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	cheack_result(t_stack **stack_a, t_stack **stack_b)
{
	if (class_result(stack_a) && !(*stack_b))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	class_stack_cheack(t_stack **stack_a, t_stack **stack_b, char *head)
{
	if (!ft_strncmp(head, "pa\n", 3))
		pa(stack_a, stack_b);
	else if (!ft_strncmp(head, "pb\n", 3))
		pb(stack_a, stack_b);
	else if (!ft_strncmp(head, "sa\n", 3))
		sa(stack_a);
	else if (!ft_strncmp(head, "sb\n", 3))
		sb(stack_b);
	else if (!ft_strncmp(head, "ss\n", 3))
		ss(stack_a, stack_b);
	else if (!ft_strncmp(head, "ra\n", 3))
		ra(stack_a);
	else if (!ft_strncmp(head, "rb\n", 3))
		rb(stack_b);
	else if (!ft_strncmp(head, "rr\n", 3))
		rr(stack_a, stack_b);
	else if (!ft_strncmp(head, "rra\n", 4))
		rra(stack_a);
	else if (!ft_strncmp(head, "rrb\n", 4))
		rrb(stack_b);
	else if (!ft_strncmp(head, "rrr\n", 4))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*head;

	while (1)
	{
		head = get_next_line (0);
		if (!class_stack_cheack(stack_a, stack_b, head))
		{
			free (head);
			break ;
		}
		free(head);
	}
	cheack_result(stack_a, stack_b);
}

int	main(int ac, char *av[])
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac <= 1)
		return (0);
	if (!stack_aid_error(av))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	if (cheak_err(av))
	{
		stack_a = (t_stack **)malloc(sizeof(t_stack *));
		stack_b = (t_stack **)malloc(sizeof(t_stack *));
		*stack_a = NULL;
		*stack_b = NULL;
		fill_stack_a(av, stack_a);
		checker(stack_a, stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
