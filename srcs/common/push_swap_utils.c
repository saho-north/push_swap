/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sakitaha <sakitaha@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 01:06:41 by sakitaha          #+#    #+#             */
/*   Updated: 2023/08/11 01:27:48 by sakitaha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap_common.h"

int	ft_issign(int c)
{
	return (c == '+' || c == '-');
}

int	ft_isdigsig(int c)
{
	return (ft_isdigit(c) || ft_issign(c));
}

int	ft_isspace(int c)
{
	return (c == ' ' || ('\t' <= c && c <= '\r'));
}
