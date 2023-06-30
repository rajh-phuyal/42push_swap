/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/30 01:22:56 by rphuyal          ###   ########.fr       */
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

/* find a way to feep tract of numbers of members added in a family
also the family should be assigned based on the index and the range of
differencr between min and the max*/
void	get_family_number(t_carrier *pigeons, int max_siblings, int families)
{
	int		index;
	int		count;
	int		family;
	t_stack *head;

	family = 1;
	count = 0;
	head = pigeons->head_a;
	while (head)
	{
		if (count == max_siblings)
		{
			count = 0;
			family++;
		}
		index = find_index_arr(pigeons->sorted, pigeons->size, head->value);
		head->family = family;
		count++;
		head = head->next;
	}
}

void	find_siblings(t_carrier *pigeons)
{
	int *sorted;
	int	families;
	int	max_siblings;

	max_siblings = 5;
	families = pigeons->size / max_siblings + (pigeons->size % max_siblings != 0);
	ft_printf("size: %i\n", pigeons->size);
	ft_printf("%d families\n", families);
	ft_printf("%d max siblings\n", max_siblings);
	ft_printf("%d min\n", pigeons->min_a);
	ft_printf("%d max\n", pigeons->max_a);
	pigeons->sorted = map_and_sort(pigeons->head_a, pigeons->size);
	if (!sorted)
		return ;
	get_family_number(pigeons, max_siblings, families);
}
