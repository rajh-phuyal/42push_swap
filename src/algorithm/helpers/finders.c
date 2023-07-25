/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/25 22:10:37 by rphuyal          ###   ########.fr       */
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

int	find_moves(t_carrier *pigeons, int val, int *direction, int stk)
{
	int	index;

	if (stk == STACK_A)
	{
		index = find_position(pigeons->head_a, val);
		*direction = (index > (pigeons->size_a - index)) + (NORTH);
		if (*direction == NORTH)
			return (index);
		else
			return (pigeons->size_a - index);
	}
	else if (stk == STACK_B)
	{
		index = find_position(pigeons->head_b, val);
		*direction = (index > (pigeons->size_b - index)) + (NORTH);
		if (*direction == NORTH)
			return (index);
		else
			return (pigeons->size_b - index);
	}
	else
		return (-1);
}

int	find_index_in_arr(int *arr, int size, int to_find)
{
	if (size == 0)
		return (-1);
	if (arr[size - 1] == to_find)
		return (size - 1);
	return (find_index_in_arr(arr, size - 1, to_find));
}

void	find_population(t_carrier *pigeons)
{
	int		families;
	int		siblings;

	siblings = ((pigeons->size_a == 100) * 12) + \
				(35 * (pigeons->size_a == 500));
	if (!siblings)
		siblings = ((10 * (pigeons->size_a < 100)) + \
				(25 * (pigeons->size_a > 100)) + \
				(40 * (pigeons->size_a > 500)));
	families = (pigeons->size_a / siblings) + \
		(pigeons->size_a % siblings != 0);
	pigeons->siblings = siblings;
	pigeons->families = families;
}

void	find_siblings(t_carrier *pigeons)
{
	int		index;
	int		*sorted;
	t_stack	*head;

	find_population(pigeons);
	sorted = map_and_sort(pigeons->head_a, pigeons->size_a);
	if (!sorted)
		return ;
	head = pigeons->head_a;
	while (head)
	{
		index = find_index_in_arr(sorted,
				pigeons->size_a, head->value);
		if (index >= (pigeons->size_a - 4))
		{
			head->family = -1;
		}
		else
			head->family = ((pigeons->families / pigeons->siblings) - \
				(pigeons->families >= pigeons->siblings)) + \
				(index / pigeons->siblings);
		head = head->next;
	}
	free(sorted);
}
