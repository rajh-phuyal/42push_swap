/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sorting_portal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/20 03:11:41 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	only_three(t_carrier *pigeons, t_stack *head, t_stack *tail, int size)
{
	if (size == 2)
		sa(pigeons, 0);
	else if (head->value > head->next->value && head->value > tail->value)
	{
		if (head->next->value < tail->value)
			ra(pigeons, 0);
		else if (head->next->value > tail->value)
		{
			sa(pigeons, 0);
			rra(pigeons, 0);
		}
	}
	else if (head->next->value > head->value && head->next->value > tail->value)
	{
		if (head->value > tail->value)
			rra(pigeons, 0);
		else if (head->value < tail->value)
		{
			sa(pigeons, 0);
			ra(pigeons, 0);
		}
	}
	else if (head->value > head->next->value && \
	tail->value > (head->value && head->next->value))
		sa(pigeons, 0);
}

void	the_sorting_portal(t_carrier *pigeons)
{
	ft_printf(" ----- STACK A -----\n");
	print_stack(pigeons->head_a);
	ft_printf(" ----- STACK B -----\n");
	print_stack(pigeons->head_b);

	pigeons->size = stack_size(pigeons->head_a);
	if (pigeons->size <= 3)
		only_three(pigeons, pigeons->head_a, pigeons->tail_a, pigeons->size);
	else
	{
		rollback(pigeons, pigeons->head_a);
		find_species(pigeons);
		send_odds(pigeons, pigeons->odd_count);
		send_evens(pigeons, pigeons->even_count);
		send_back(pigeons);
	}
	ft_printf(" ----- STACK A -----\n");
	print_stack(pigeons->head_a);
	ft_printf(" ----- STACK B -----\n");
	print_stack(pigeons->head_b);
}
