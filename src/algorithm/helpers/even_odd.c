/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   even_odd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 17:32:33 by rphuyal          ###   ########.fr       */
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
		ft_printf("what?: %i\n", (head->value % 2 == 0));
		if (head->value % 2 == 0)
			pigeons->even_count++;
		else
			pigeons->odd_count++;
		head = head->next;
	}
}
