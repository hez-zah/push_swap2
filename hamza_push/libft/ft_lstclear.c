/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:07:53 by hez-zahi          #+#    #+#             */
/*   Updated: 2022/11/05 17:47:50 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*test;

	if (!lst)
		return ;
	test = NULL;
	while (*lst)
	{
		test = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = test;
	}
	*lst = NULL;
}
