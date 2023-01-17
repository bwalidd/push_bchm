/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:03:44 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/18 20:58:49 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_rev(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;
	t_stack	*prelast;

	last = *a;
	while (last && last->next)
		last = last->next;
	prelast = *a;
	while (prelast && prelast->next && prelast->next->next)
		prelast = prelast->next;
	tmp = *a;
	*a = last;
	(*a)->next = tmp;
	prelast->next = NULL;
}

void	rra(t_stack **a, int flag)
{
	if (!(*a) || get_size(*a) < 2)
		return ;
	rotate_rev(a);
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int flag)
{
	if (!(*b) || get_size(*b) < 2)
		return ;
	rotate_rev(b);
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	if (!(*a) || !(*b) || get_size(*a) < 2 || get_size(*b) < 2)
		return ;
	rotate_rev(a);
	rotate_rev(b);
	if (flag)
		write(1, "rrr\n", 4);
}
