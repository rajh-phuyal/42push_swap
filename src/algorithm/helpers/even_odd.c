/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/21 20:40:32 by rphuyal          ###   ########.fr       */
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

int	*find_ranges(t_carrier *pigeons)
{
	int	*range;

	range = (int *)malloc(sizeof(int) * 4);
	if (!range)
		return (NULL);
	range[0] = pigeons->max_odd;
	range[1] = pigeons->max_odd - (pigeons->odd_count / 2);
	range[2] = pigeons->min_even;
	range[3] = pigeons->min_even + (pigeons->odd_count / 2);
	return (range);
}
