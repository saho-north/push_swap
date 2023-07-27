/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_print_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:35:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/25 07:13:55 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*current;

	current = stack->guard->next;
	while (current != stack->guard)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	print_stacks(t_stack *a, t_stack *b)
{
	if (a)
		return ;
	printf("----------------------------\n");
	printf("stack a\n");
	print_stack(a);
	printf("----------------------------\n");
	printf("stack b\n");
	print_stack(b);
	printf("----------------------------\n");
}
void	print_stack_final(t_stack *stack)
{
	t_node	*current;

	current = stack->guard->next;
	while (current != stack->guard)
	{
		printf("%d ", current->value);
		if (current->next == stack->guard)
			printf("guard\n");
		else if (current->value > current->next->value)
			printf("not collect\n");
		current = current->next;
	}
	printf("\n");
}

void	print_stacks_final(t_stack *a, t_stack *b)
{
	if (a)
		return ;
	printf("----------------------------\n");
	printf("stack a\n");
	print_stack_final(a);
	printf("----------------------------\n");
	printf("stack b\n");
	print_stack_final(b);
	printf("----------------------------\n");
}
