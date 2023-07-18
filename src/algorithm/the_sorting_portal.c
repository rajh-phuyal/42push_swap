/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sorting_portal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/18 22:04:14 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	the_sorting_portal(t_carrier *pigeons)
{
	pigeons->size_a = stack_size(pigeons->head_a);
	if (pigeons->size_a <= 3)
		sort_three(pigeons, pigeons->head_a, pigeons->tail_a, pigeons->size_a);
	else if (pigeons->size_a <= 5)
		sort_five(pigeons);
	else if (pigeons->size_a <= 10)
		sort_ten(pigeons);
	else
	{
		rollback(pigeons, pigeons->head_a, STACK_A);
		find_siblings(pigeons);
		send_to_b(pigeons, 0, 1);
		send_back(pigeons);
	}
}
