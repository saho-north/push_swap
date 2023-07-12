/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 19:21:12 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/12 23:54:01 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nord_to_stack(int num, t_stack *stack)
{
	t_nord	*node;

	node = (t_nord *)malloc(sizeof(t_nord));
	if (!node)
		free_stack_with_error(stack);
	node->next = stack->guard_nord;
	node->prev = stack->guard_nord->prev;
	stack->guard_nord->prev->next = node;
	stack->guard_nord->prev = node;
	node->value = num;
	node->is_guard_nord = false;
	node->is_pivot = false;
	stack->size++;
}

t_nord	*create_guard_nord(void)
{
	t_nord	*guard_nord;

	guard_nord = (t_nord *)malloc(sizeof(t_nord));
	if (!guard_nord)
		return (NULL);
	guard_nord->next = guard_nord;
	guard_nord->prev = guard_nord;
	guard_nord->value = 0;
	guard_nord->is_guard_nord = true;
	guard_nord->is_pivot = false;
	return (guard_nord);
}

t_stack	*create_empty_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		exit_with_print_error();
	stack->guard_nord = create_guard_nord();
	if (!stack->guard_nord)
	{
		free(stack);
		exit_with_print_error();
	}
	stack->size = 0;
	return (stack);
}

static void	check_if_duplicate(int num, t_stack *stack)
{
	t_nord	*node;

	node = stack->guard_nord->next;
	while (node && node != stack->guard_nord)
	{
		if (node->value == num)
			free_stack_with_error(stack);
		node = node->next;
	}
}

t_stack	*parse_input(int argc, const char **argv)
{
	t_stack		*stack;
	const char	*str;
	const char	*endpos;
	long		num;

	stack = create_empty_stack();
	while (argc--)
	{
		str = *argv;
		while (*str)
		{
			num = ft_strtol(str, &endpos);
			if (num < INT_MIN || INT_MAX < num)
				free_stack_with_error(stack);
			check_if_duplicate((int)num, stack);
			push_nord_to_stack((int)num, stack);
			str = endpos;
		}
		argv++;
	}
	return (stack);
}
