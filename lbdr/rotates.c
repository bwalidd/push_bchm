/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:42:47 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/18 20:57:15 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *a;
	*a = (*a)->next;
	last = *a;
	while (last && last->next)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	ra(t_stack **a, int flag)
{
	if (!(*a) || get_size(*a) < 2)
		return ;
	rotation(a);
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int flag)
{
	if (!(*b) || get_size(*b) < 2)
		return ;
	rotation(b);
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	if (!(*a) || !(*b) || get_size(*a) < 2 || get_size(*b) < 2)
		return ;
	rotation(a);
	rotation(b);
	if (flag)
		write(1, "rr\n", 3);
}
