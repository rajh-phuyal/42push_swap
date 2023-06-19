/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_sorting_portal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:10:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 17:35:44 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	the_sorting_portal(t_carrier *pigeons)
{
	pigeons->size = stack_size(pigeons->head_a);
	rollback(pigeons, pigeons->head_a);
	find_species(pigeons);
	ft_printf("EVEN: %i\nODD: %i\n", pigeons->even_count, pigeons->odd_count);
	send_evens(pigeons, pigeons->even_count);
	print_stack(pigeons->head_a);
	return ;
}
