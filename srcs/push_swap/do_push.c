/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 21:28:36 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:09:07 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push(t_stack *stack_from, t_stack *stack_to)
{
	t_node	*node_to_push;
	t_node	*guard_from;
	t_node	*guard_to;

	guard_from = stack_from->guard;
	guard_to = stack_to->guard;
	node_to_push = stack_from->guard->next;
	if (node_to_push == guard_from)
		return ;
	guard_from->next = node_to_push->next;
	node_to_push->next->prev = guard_from;
	stack_from->size--;
	node_to_push->next = guard_to->next;
	node_to_push->prev = guard_to;
	guard_to->next = node_to_push;
	node_to_push->next->prev = node_to_push;
	stack_to->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
