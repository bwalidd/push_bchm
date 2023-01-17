/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:02:33 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/19 18:29:00 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_algo(t_stack **b, t_stack **a, int size)
{
	int	mid;

	while (size > 0)
	{
		mid = size / 2;
		if (mid > get_pos(*b, size - 1))
		{
			while ((*b)->index != size - 1)
				rb(b, 1);
			pa(a, b, 1);
		}
		else
		{
			while ((*b)->index != size - 1)
				rrb(b, 1);
			pa(a, b, 1);
		}
		size--;
	}
}

void	sort_s3(t_stack **stack_a)
{
	int	high;

	if (check_sort(*stack_a))
		return ;
	high = high_idx(*stack_a);
	if ((*stack_a)->index == high)
		ra(stack_a, 1);
	else if ((*stack_a)->next->index == high)
		rra(stack_a, 1);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int size, int *tab)
{
	if (size == 2 && check_sort(*stack_a) == 0)
		sa(stack_a, 1);
	else if (size == 3 && check_sort(*stack_a) == 0)
		sort_s3(stack_a);
	else if (size > 3 && size <= 10 && check_sort(*stack_a) == 0)
		sort_max10(stack_a, stack_b);
	else if (size > 10 && size <= 100 && check_sort(*stack_a) == 0)
	{
		sort_100(stack_a, stack_b, tab, 15);
		main_algo(stack_b, stack_a, get_size(*stack_b));
	}
	else if (size > 100 && check_sort(*stack_a) == 0)
	{
		sort_100(stack_a, stack_b, tab, 30);
		main_algo(stack_b, stack_a, get_size(*stack_b));
	}
}

void	sort_100(t_stack **a, t_stack **b, int *arr, int magic)
{
	int	i;
	int	size;

	i = 0;
	size = get_size(*a);
	while (size > 0)
	{
		if ((*a)->value <= arr[i])
		{
			pb(b, a, 1);
			if (get_size(*b) > 2)
				rb(b, 1);
			size--;
			i++;
		}
		else if ((*a)->value > arr[i] && (*a)->index <= i + magic)
		{
			pb(b, a, 1);
			size--;
			i++;
		}
		else
			if (size > 2)
				ra(a, 1);
	}
}
