/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:06:42 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/04 08:08:40 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*guard;
	t_node	*first_node;
	t_node	*second_node;

	guard = stack->guard;
	first_node = guard->next;
	second_node = first_node->next;
	if (first_node == guard || second_node == guard)
		return ;
	first_node->next = second_node->next;
	first_node->prev = second_node;
	first_node->next->prev = first_node;
	second_node->next = first_node;
	second_node->prev = guard;
	guard->next = second_node;
}

void	sa(t_stack *a)
{
	swap(a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack *b)
{
	swap(b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
