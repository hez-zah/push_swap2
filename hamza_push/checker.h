/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 03:14:44 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 15:18:26 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct checker
{
	int				indx;
	char			*count;
	long			nbr;
	struct checker	*next;
}t_stack;

int		cheak_err(char *av[]);
void	fill_stack_a(char *av[], t_stack **stack_a);
int		class_result(t_stack **stack_a);
int		stack_aid_error(char **av);

t_stack	*lst_new(char *content);
t_stack	*lst_last(t_stack *lst);
void	lst_add_back(t_stack **lst, t_stack *new);
int		ft_new_atoi(const char *str);

char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	sa(t_stack **tmp_a);
void	sb(t_stack **tmp_b);
void	ss(t_stack **tmp_a, t_stack **tmp_b);
void	pa(t_stack **tmp_a, t_stack **tmp_b);
void	pb(t_stack **tmp_a, t_stack **tmp_b);
void	ra(t_stack **tmp_a);
void	rb(t_stack **tmp_b);
void	rr(t_stack **tmp_a, t_stack **tmp_b);
void	rra(t_stack	**tmp_a);
void	rrb(t_stack	**tmp_b);
void	rrr(t_stack **tmp_a, t_stack **tmp_b);

#endif
