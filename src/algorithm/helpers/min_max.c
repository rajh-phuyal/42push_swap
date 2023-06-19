/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:04:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 02:26:57 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	reset_all_limits(t_carrier *pigeons)
{
	pigeons->min_even = INT_MAX;
	pigeons->max_even = INT_MIN;
	pigeons->min_odd = INT_MAX;
	pigeons->max_odd = INT_MIN;
}

void	find_min_max(t_carrier *pigeons, t_stack *stack, int index)
{
	if (!stack)
		return ;
	if (stack->value % 2 == 0)
	{
		if (stack->value < pigeons->min_even)
			pigeons->min_even = stack->value;
		if (stack->value > pigeons->max_even)
			pigeons->max_even = stack->value;
	}
	else
	{
		if (stack->value < pigeons->min_odd)
			pigeons->min_odd = stack->value;
		if (stack->value > pigeons->max_odd)
			pigeons->max_odd = stack->value;
	}
	stack->index = index;
	find_min_max(pigeons, stack->next, index + 1);
}