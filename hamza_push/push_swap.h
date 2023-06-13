/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hez-zahi <hez-zahi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 01:02:21 by hez-zahi          #+#    #+#             */
/*   Updated: 2023/06/13 17:04:58 by hez-zahi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct push
{
	long		nbr;
	int			len;
	int			sub;
	int			*lis;
	int			index;
	int			test;
	int			broth;
	int			move;
	char		*str;
	struct push	*next;
}t_stake;

t_stake	*creat_stak(char *av[]);
int		cheak_err(char *av[]);
int		cheak_err_doubl(t_stake **A);
int		comme_true(t_stake **A);
int		stack_aid_error(char **av);

char	*ft_strjoin(char const *s1, char const *s2);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

void	ra(t_stake **tmp_a);
void	rb(t_stake **tmp_b);
void	rr(t_stake **tmp_a, t_stake **tmp_b);
void	rra(t_stake **tmp_a);
void	rrb(t_stake **tmp_b);
void	rrr(t_stake **tmp_a, t_stake **tmp_b);
void	sa(t_stake **tmp_a);
void	sb(t_stake **tmp_b);
void	ss(t_stake **tmp_a, t_stake **tmp_b);
void	pa(t_stake **tmp_a, t_stake **tmp_b);
void	pb(t_stake **tmp_a, t_stake **tmp_b);

t_stake	*lis(char *av[], t_stake *Arr);
void	min_push_swap(t_stake **A, t_stake **B);
int		size_lst(t_stake **A);
void	indx_lst(t_stake **old1, t_stake **old2);
void	pucher(t_stake **A, t_stake **B);
t_stake	*broth_to_b(t_stake **A, t_stake **B);
int		min_a(t_stake **A);
int		max_a(t_stake **A);
void	nbr_move(t_stake **A, t_stake **B);
int		len(t_stake **A_B);
void	class(t_stake **A, t_stake **B, int len_a, int len_b);
void	push_swap(char *av[]);

void	free_stack(t_stake **A, t_stake **B);

#endif
