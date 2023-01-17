/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:13:39 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/19 18:11:46 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	tmp;

	if (!(*a) || get_size(*a) < 2)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	int	tmp;

	if (!(*b) || get_size(*b) < 2)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	int	tmp;

	if (!(*a) || !(*b) || get_size(*a) < 2 || get_size(*b) < 2)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	if (flag == 1)
		write(1, "ss\n", 3);
}
