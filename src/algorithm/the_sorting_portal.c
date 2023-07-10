/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sorting_portal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/10 17:32:29 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	the_sorting_portal(t_carrier *pigeons)
{
	pigeons->size = stack_size(pigeons->head_a);
	if (pigeons->size <= 3)
		only_three(pigeons, pigeons->head_a, pigeons->tail_a, pigeons->size);
	else
	{
		rollback(pigeons, pigeons->head_a, STACK_A);
		find_siblings(pigeons);
		ft_printf("---- STACK A ----\n");
		print_stack(pigeons->head_a);
		send_to_b(pigeons);
		ft_printf("----- STACK B -----\n");
		print_stack(pigeons->head_b);
		send_back(pigeons);
	}
	ft_printf("---- FINAL STACK A ----\n");
	print_stack(pigeons->head_a);
}
