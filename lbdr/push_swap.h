/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:55:46 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/17 02:52:23 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <dlfcn.h>
# include <execinfo.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct list
{
	int			value;
	int			index;
	struct list	*next;	
}	t_stack;

int		check_sort(t_stack *stack);
int		is_num(char *av);
int		is_zero(char *av);
int		checkdouble(char **av);
int		is_valid(char **av);
void	free_stack(t_stack **a);
void	exit_sys(t_stack **a, t_stack **b);
int		cmp(const char *s, const char *s1);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	assign_index(t_stack *stack_a, int size);
t_stack	*fill_stack(int ac, char **av);
void	pa(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **b, t_stack **a, int flag);
void	rotate_rev(t_stack **a);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);
void	rotation(t_stack **a);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
int		find_low_idx(t_stack *s);
void	sort_max10(t_stack **a, t_stack **b);
void	main_algo(t_stack **b, t_stack **a, int size);
void	sort_s3(t_stack **stack_a);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size, int *tab);
void	sort_100(t_stack **a, t_stack **b, int *arr, int magic);
t_stack	*new_stack(int val);
int		get_size(t_stack *s);
int		high_idx(t_stack *s);
int		get_pos(t_stack *a, int idx);
void	sa(t_stack **a, int flag);
long	ft_atoi(const char *str);
int		*fill_tab(t_stack *a, int size);
int		ft_strcmp(const char *s1, const char *s2);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);
char	**ft_split(char const *s, char c);

#endif