/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max10.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 17:03:58 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/14 16:18:04 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_low_idx(t_stack *s)
{
	int	i;

	i = s->index;
	while (s)
	{
		if (s->index < i)
			i = s->index;
		s = s->next;
	}
	return (i);
}

void	sort_return(int *i, t_stack **a, t_stack **b)
{
	sort_s3(a);
	while ((*i) != 0)
	{
		pa(a, b, 1);
		(*i)--;
	}
}

void	sort_max10(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (get_size(*a) > 3)
	{
		if ((get_size(*a) / 2) > get_pos(*a, find_low_idx(*a)))
		{
			while ((*a)->index != i)
				ra(a, 1);
			if (check_sort(*a))
				break ;
			pb(b, a, 1);
		}
		else
		{
			while ((*a)->index != i)
				rra(a, 1);
			if (check_sort(*a))
				break ;
			pb(b, a, 1);
		}
		i++;
	}
	sort_return(&i, a, b);
}
