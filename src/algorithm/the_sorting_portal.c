/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sorting_portal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/17 23:04:30 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	the_sorting_portal(t_carrier *pigeons)
{
	pigeons->size = stack_size(pigeons->head_a);
	if (pigeons->size <= 3)
		only_three(pigeons, pigeons->head_a, pigeons->tail_a, pigeons->size);
	else if (pigeons->size <= 5)
		only_five(pigeons);
	else
	{
		rollback(pigeons, pigeons->head_a, STACK_A);
		find_siblings(pigeons);
		send_to_b(pigeons);
		// send_back(pigeons);
	}
	// ft_printf("---- FINAL STACK A ----\n");
	// print_stack(pigeons->head_a);
}
