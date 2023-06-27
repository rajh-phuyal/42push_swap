/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sending_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:18 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/26 21:41:29 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

unsigned long	create_hash_id(int family)
{
    unsigned long id;

    id = 5381;
    id = ((id << 3) + id) + family;
    return (id);
}

int	find_position(t_stack *stack, int to_find)
{
	if (!stack)
		return (-1);
	if (stack->value == to_find)
		return (stack->index);
	else
		return (find_position(stack->next, to_find));
}

int	find_moves(t_carrier *pigeons, int val, int *direction)
{
	int	index;

	index = find_position(pigeons->head_a, val);
	*direction = (index > (pigeons->size - index)) + (NORTH);
	if (*direction == NORTH)
		return (index);
	else
		return (pigeons->size - index);
}
