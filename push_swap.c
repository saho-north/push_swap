/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:04:22 by sakitaha          #+#    #+#             */
/*   Updated: 2023/07/13 00:09:20 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_stack	*stack_a;

	if (argc == 1 || !is_valid_arg(--argc, ++argv))
		exit_with_print_error();
	stack_a = parse_input(argc, argv);
	if (!stack_a)
		exit_with_print_error();
	print_stack(stack_a);
	free_stack(stack_a);
	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
