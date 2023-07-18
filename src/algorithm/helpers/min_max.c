/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 02:04:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/18 18:43:00 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	find_min_max(t_carrier *pigeons, t_stack *stack, int index, int stk)
{
	if (!stack)
		return ;
	if (stk == STACK_A)
	{
		if (stack->value < pigeons->min_a)
			pigeons->min_a = stack->value;
		if (stack->value > pigeons->max_a)
			pigeons->max_a = stack->value;
	}
	else if (stk == STACK_B)
	{
		if (stack->value < pigeons->min_b)
			pigeons->min_b = stack->value;
		if (stack->value > pigeons->max_b)
			pigeons->max_b = stack->value;
	}
	stack->index = index;
	find_min_max(pigeons, stack->next, index + 1, stk);
}

void	rollback(t_carrier *pigeons, t_stack *stack, int stk)
{
	pigeons->min_a = INT_MAX;
	pigeons->max_a = INT_MIN;
	pigeons->min_b = INT_MAX;
	pigeons->max_b = INT_MIN;
	find_min_max(pigeons, stack, 0, stk);
}
