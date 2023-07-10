/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/10 15:33:44 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	send_back(t_carrier *pigeons)
{
	if (!pigeons->head_b)
		return ;
	while (pigeons->head_b)
	{
		// if (pigeons->head_b->value < pigeons->tail_b->value)
		// 	rrb(pigeons, 0);
		pa(pigeons);
	}
}
