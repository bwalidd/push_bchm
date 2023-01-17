/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:12:24 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/19 19:14:47 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void	execute_command(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(a, b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(a, b, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(b, a, 0);
	else
		exit_sys(NULL, NULL);
}

void	validate_args(int *ac, char **av)
{
	if (*ac < 2)
		return ;
	if (is_valid(av) == 0)
		exit_sys(NULL, NULL);
}

int	main(int ac, char **av)
{
	char	*line;
	t_stack	*st_a;
	t_stack	*st_b;
	int		stack_size;

	validate_args(&ac, av);
	st_a = fill_stack(ac, av);
	stack_size = get_size(st_a);
	assign_index(st_a, stack_size - 1);
	line = get_next_line(0);
	while (line)
	{
		execute_command(line, &st_a, &st_b);
		free(line);
		line = get_next_line(0);
	}
	if (!st_b && st_a && check_sort(st_a) == 1)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stack(&st_a);
	free_stack(&st_b);
	return (0);
}
