/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:20:44 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 01:26:50 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_stack *stack)
{
	t_node	*guard;
	t_node	*first_node;
	t_node	*last_node;
	t_node	*second_last_node;

	guard = stack->guard;
	if (guard->next == guard->prev)
		return ;
	first_node = guard->next;
	last_node = guard->prev;
	second_last_node = last_node->prev;
	guard->next = last_node;
	guard->prev = second_last_node;
	last_node->next = first_node;
	last_node->prev = guard;
	second_last_node->next = guard;
	first_node->prev = last_node;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putendl_fd("rrr", 1);
}

void	multi_rrr(t_stack *a, t_stack *b, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		rrr(a, b);
		i++;
	}
}
