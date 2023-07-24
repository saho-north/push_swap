/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 03:31:28 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/24 23:36:14 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_possible_pivots(int possible_pivots[], int arrsize)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < arrsize - 1)
	{
		j = i + 1;
		while (j < arrsize)
		{
			if (possible_pivots[i] > possible_pivots[j])
			{
				tmp = possible_pivots[i];
				possible_pivots[i] = possible_pivots[j];
				possible_pivots[j] = tmp;
			}
			j++;
		}
		i++;
	}
	////printf("pivot[%d] = %d\n", arrsize / 2, possible_pivots[arrsize / 2]);
	return (possible_pivots[arrsize / 2]);
}

static int	median_of_three(t_stack *stack, int size)
{
	t_node	*node;
	int		possible_pivots[3];
	int		i;

	node = stack->guard->next;
	possible_pivots[0] = node->value;
	i = 0;
	while (i < size - 1)
	{
		if (i == size / 2)
			possible_pivots[1] = node->value;
		node = node->next;
		i++;
	}
	possible_pivots[2] = node->value;
	return (check_possible_pivots(possible_pivots, 3));
}

static int	median_of_five(t_stack *stack, int size)
{
	t_node	*node;
	int		possible_pivots[5];
	int		i;
	int		j;

	node = stack->guard->next;
	i = 0;
	j = 0;
	while (i < size && j < 5)
	{
		if (i == (size / 5) * j)
		{
			possible_pivots[j] = node->value;
			////printf("i = %d, possible_pivots[%d] = %d\n", i, j,
			//		possible_pivots[j]);
			j++;
		}
		node = node->next;
		i++;
	}
	return (check_possible_pivots(possible_pivots, 5));
}

int	get_pivot(t_stack *stack, int size)
{
	//printf("get_pivot for size %d\n", size);
	if (size < 5)
		return (median_of_three(stack, size));
	else
		return (median_of_five(stack, size));
}
