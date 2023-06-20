/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/20 02:58:06 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	send_back(t_carrier *pigeons)
{
	ft_printf("\nstage two\n");
	ft_printf(" ----- STACK A -----\n");
	print_stack(pigeons->head_a);
	ft_printf(" ----- STACK B -----\n");
	print_stack(pigeons->head_b);
	ft_printf("\nstage two\n");


	while (pigeons->head_b)
	{
		if (pigeons->head_b->value < pigeons->tail_b->value)
			rrb(pigeons, 0);
		pa(pigeons);
	}
}
