/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbouwach <wbouwach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:06:46 by wbouwach          #+#    #+#             */
/*   Updated: 2022/12/14 15:20:09 by wbouwach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	sortt(int *arr, int size)
{
	int	i;
	int	j;
	int	min_idx;

	i = 0;
	while (i < size - 1)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (arr[j] < arr[min_idx])
				min_idx = j;
			j++;
		}
		swap(&arr[min_idx], &arr[i]);
		i++;
	}
}

int	*fill_tab(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * size);
	i = 0;
	if (!arr)
		return (0);
	while (a)
	{
		arr[i] = a->value;
		a = a->next;
		i++;
	}
	sortt(arr, size);
	return (arr);
}
