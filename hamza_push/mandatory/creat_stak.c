/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_stak.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:36:31 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 18:58:00 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_ret(char **ret)
{
	int	i;

	i = -1;
	while (ret[++i])
		free(ret[i]);
	free(ret[i]);
}

t_stake	*ft_lst_new(char *nbr, int index)
{
	t_stake	*new;

	new = (t_stake *)malloc(sizeof(t_stake));
	if (!new)
		return (NULL);
	new->nbr = ft_atoi(nbr);
	if (new->nbr > 2147483647 || new->nbr < -2147483648)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	new->len = 1;
	new->sub = 0;
	new->test = 0;
	new->lis = NULL;
	new->index = index;
	new->next = NULL;
	new->broth = 0;
	new->move = 0;
	new->str = NULL;
	return (new);
}

t_stake	*last_add(t_stake *head, char *nbr, int index)
{
	t_stake	*tmp;
	t_stake	*b;

	b = ft_lst_new(nbr, index);
	if (!head)
		head = b;
	else
	{
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = b;
	}
	return (head);
}

char	*get_av(char *av[])
{
	char	*new;
	char	*old;
	int		i;

	i = 1;
	new = ft_strdup(av[1]);
	i++;
	while (av[i])
	{
		old = new;
		new = ft_strjoin(new, av[i]);
		free(old);
		i++;
	}
	return (new);
}

t_stake	*creat_stak(char *av[])
{
	t_stake	*head;
	char	**ret;
	char	*new;
	int		len;
	int		i;

	head = NULL;
	new = get_av(av);
	ret = ft_split(new, ' ');
	free(new);
	len = 0;
	while (ret[len])
		len++;
	i = 0;
	while (i < len)
	{
		head = last_add(head, ret[i], i);
		i++;
	}
	free_ret(ret);
	return (head);
}
