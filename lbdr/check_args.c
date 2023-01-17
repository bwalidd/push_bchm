/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:55:40 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/19 18:19:16 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_num(char *av)
{
	int	i;

	i = 0;
	if ((av[i] == '-' || av[i] == '+') && av[i + 1])
		i++;
	while (av[i] && av[i] >= '0' && av[i] <= '9')
		i++;
	if (av[i] != '\0' && (av[i] < '0' || av[i] > '9'))
		return (0);
	return (1);
}

int	is_zero(char *av)
{
	int	i;

	i = 0;
	if (av[i] == '+' || av[i] == '-')
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i])
		return (0);
	return (1);
}

int	checkdouble(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (((cmp(av[i], av[j]) == 0) || ft_atoi(av[i]) == ft_atoi(av[j]))
				&& j != i)
				return (1);
			j++;
		}
		if (!av[i][0])
			return (1);
		i++;
	}
	return (0);
}

int	is_valid(char **av)
{
	int	nbzero;
	int	i;

	i = 1;
	nbzero = 0;
	while (av[i])
	{
		if (is_num(av[i]) == 0)
			return (0);
		nbzero += is_zero(av[i]);
		i++;
	}
	if (nbzero > 1)
		return (0);
	if (checkdouble(av))
		return (0);
	return (1);
}
