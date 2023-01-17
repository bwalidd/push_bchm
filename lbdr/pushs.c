/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:31:47 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/17 23:43:52 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int flag)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	if (flag)
		write(1, "pb\n", 3);
}
