/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 14:07:15 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/09 03:07:26 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "push_swap_common.h"

# define STACK_A 1
# define STACK_B 0

bool	is_reverse_sorted(t_stack *stack, size_t size);
void	sort(t_stack *a, t_stack *b);
void	sort_small(t_stack *a, t_stack *b, size_t size, bool type);
void	compaction(t_stack *stack);
void	partition(t_stack *a, t_stack *b);
void	partition_a(t_stack *a, t_stack *b, size_t size, size_t max_id);
void	partition_b(t_stack *a, t_stack *b, size_t size, size_t min_id);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	multi_rrr(t_stack *a, t_stack *b, size_t count);

#endif
