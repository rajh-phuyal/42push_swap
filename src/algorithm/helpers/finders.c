/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/29 23:39:48 by rphuyal          ###   ########.fr       */
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

int		find_index_arr(int *arr, int size, int to_find)
{
	if (size == 0)
		return (-1);
	if (arr[size - 1] == to_find)
		return (size - 1);
	return (find_index_arr(arr, size - 1, to_find));
}

void	get_family_number(t_carrier *pigeons, int min_siblings)
{
	t_stack *head;

	head = pigeons->head_a;
	while (head)
	{
		head->family = 0;
		head = head->next;
	}
}

void	find_siblings(t_carrier *pigeons)
{
	int *sorted;
	int	min_siblings;

	min_siblings = pigeons->size % 4;
	ft_printf("min_siblings: %i\n", min_siblings);
	pigeons->sorted = map_and_sort(pigeons->head_a, pigeons->size);
	if (!sorted)
		return ;
	get_family_number(pigeons, min_siblings);
}
