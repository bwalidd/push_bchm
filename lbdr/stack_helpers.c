/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 00:50:23 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/14 23:25:37 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int val)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = val;
	new->index = 0;
	new->next = NULL;
	return (new);
}

int	get_size(t_stack *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s)
	{
		s = s->next;
		i++;
	}
	return (i);
}

int	get_pos(t_stack *a, int idx)
{
	int	i;

	i = 1;
	while (a)
	{
		if (a->index == idx)
			return (i);
		a = a->next;
		i++;
	}
	return (i);
}

int	high_idx(t_stack *s)
{
	int	i;

	i = s->index;
	while (s)
	{
		if (s->index > i)
			i = s->index;
		s = s->next;
	}
	return (i);
}
