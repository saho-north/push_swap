/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 17:06:42 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/05 00:37:52 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/checker_bonus.h"

void	sa_bonus(t_stack *a)
{
	swap(a);
}

void	sb_bonus(t_stack *b)
{
	swap(b);
}

void	ss_bonus(t_stack *a, t_stack *b)
{
	swap(a);
	swap(b);
}
