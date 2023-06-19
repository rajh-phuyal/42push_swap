/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:18 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 16:27:24 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	find_position(t_stack *stack, int to_find)
{
	if (!stack)
		return (-1);
	if (stack->value == to_find)
		return (stack->index);
	else
		return (find_position(stack->next, to_find));
}

int	find_moves_in_dir(t_carrier *pigeons, int val, int *dir)
{
	int	index;

	index = find_position(pigeons->head_a, val);
	ft_printf("what is the pos: %i\n", index);
	*dir = SOUTH;
	return (pigeons->size - index);
}
