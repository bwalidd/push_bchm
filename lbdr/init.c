/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:38:05 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/15 21:09:42 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_to_big(t_stack *big, int *size)
{
	if (big != NULL)
		big->index = *size;
}

void	assign_index(t_stack *stack_a, int size)
{
	t_stack	*ptr;
	t_stack	*big;
	int		val;

	while (size >= 0)
	{
		ptr = stack_a;
		val = INT_MIN;
		big = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 0;
			if (ptr->value > val && ptr->index == 0)
			{
				val = ptr->value;
				big = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		assign_to_big(big, &size);
		size--;
	}
}

t_stack	*fill_stack(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			exit_sys(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)nb);
		else
			ft_lstadd_back(&stack_a, new_stack((int)nb));
		i++;
	}
	return (stack_a);
}
