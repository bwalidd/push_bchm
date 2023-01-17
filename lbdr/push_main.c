/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:39:32 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/16 21:34:50 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		*tab;
	int		size;

	if (ac < 2)
		return (0);
	if (is_valid(av) == 0)
		exit_sys(NULL, NULL);
	stack_a = fill_stack(ac, av);
	size = get_size(stack_a);
	tab = fill_tab(stack_a, size);
	assign_index(stack_a, size - 1);
	sort_stack(&stack_a, &stack_b, size, tab);
	free_stack(&stack_a);
	free_stack(&stack_b);
	free(tab);
	return (0);
}
