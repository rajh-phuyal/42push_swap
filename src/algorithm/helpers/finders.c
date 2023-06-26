/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/26 16:13:17 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	find_species(t_carrier *pigeons)
{
	t_stack	*head;

	pigeons->even_count = 0;
	pigeons->odd_count = 0;
	head = pigeons->head_a;
	while (head)
	{
		if (head->value % 2 == 0)
			pigeons->even_count++;
		else
			pigeons->odd_count++;
		head = head->next;
	}
}

size_t	arr_len(int *arr)
{
	size_t	len;

	len = 0;
	while (arr[len])
		len++;
	return (len);
}

int *find_ranges(t_carrier *pigeons)
{
	int	*range;
	int *sorted;

	range = (int *)malloc(sizeof(int) * 4);
	sorted = map_and_sort(pigeons->head_a, pigeons->size);
	if (!range || !sorted)
		return (NULL);
	ft_printf("sorted: %d\n", sorted[0]);
	for (int i = 0; i < arr_len(sorted); i++)
	{
		ft_printf("sorted: %d\n", sorted[i]);
	}
	free(sorted);
	range[0] = pigeons->max_odd;
	range[1] = pigeons->max_odd - (pigeons->odd_count / 2);
	range[2] = pigeons->min_even;
	range[3] = pigeons->min_even + (pigeons->odd_count / 2);
	return (range);
}
