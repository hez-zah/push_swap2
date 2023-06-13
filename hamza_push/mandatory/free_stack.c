/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 20:38:55 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 17:18:43 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stake **A, t_stake **B)
{
	t_stake	*tmp1;
	t_stake	*tmp2;

	tmp1 = *A;
	tmp2 = *A;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		tmp1->next = NULL;
		free(tmp1);
		tmp1 = tmp2;
	}
	tmp1 = *B;
	tmp2 = *B;
	while (tmp2)
	{
		tmp2 = tmp2->next;
		tmp1->next = NULL;
		free(tmp1);
		tmp1 = tmp2;
	}
}
