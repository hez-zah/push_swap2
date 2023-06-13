/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indx_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:37:00 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/02 16:22:14 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	indx_lst(t_stake **old1, t_stake **old2)
{
	t_stake	*new1;
	t_stake	*new2;
	int		i;

	new1 = *old1;
	new2 = *old2;
	if (!new1)
		return ;
	i = 0;
	while (new1)
	{
		new1->index = i;
		i++;
		new1 = new1->next;
	}
	if (!new2)
		return ;
	i = 0;
	while (new2)
	{
		new2->index = i;
		i++;
		new2 = new2->next;
	}
}
