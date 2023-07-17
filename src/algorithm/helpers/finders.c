/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/17 23:33:21 by rphuyal          ###   ########.fr       */
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

int	find_index_in_arr(int *arr, int size, int to_find)
{
	if (size == 0)
		return (-1);
	if (arr[size - 1] == to_find)
		return (size - 1);
	return (find_index_in_arr(arr, size - 1, to_find));
}

void	find_siblings(t_carrier *pigeons)
{
	int		index;
	int		families;
	int		max_siblings;
	t_stack	*head;

	max_siblings = 12;
	families = pigeons->size - 4 / max_siblings + \
			(pigeons->size - 4 % max_siblings != 0);
	pigeons->siblings = max_siblings;
	pigeons->families = families;
	pigeons->sorted = map_and_sort(pigeons->head_a, pigeons->size);
	if (!pigeons->sorted)
		return ;
	head = pigeons->head_a;
	while (head)
	{
		index = find_index_in_arr(pigeons->sorted, pigeons->size, head->value);
		if (index >= (pigeons->size - 4))
			head->family = -1;
		else
			head->family = ((families / max_siblings) - \
				(families >= max_siblings)) + (index / max_siblings);
		head = head->next;
	}
}
