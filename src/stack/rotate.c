/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:55:07 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/12 20:31:27 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* pushes the top of the stack a to bottom of the stack a 
shifting all other elements up one index. */
void	ra(t_carrier *pigeons)
{
	if (!pigeons->head_a)
		return ;
	pigeons->tail_a->next = pigeons->head_a;
	pigeons->tail_a = pigeons->head_a;
	pigeons->head_a = pigeons->head_a->next;
	pigeons->tail_a->next = NULL;
	ft_printf("ra\n");
}

/* pushes the top of the stack b to bottom of the stack b
shifting all other elements up one index. */
void	rb(t_carrier *pigeons)
{
	if (!pigeons->head_b)
		return ;
	pigeons->tail_b->next = pigeons->head_b;
	pigeons->tail_b = pigeons->head_b;
	pigeons->head_b = pigeons->head_b->next;
	pigeons->tail_b->next = NULL;
	ft_printf("ra\n");
}

/* call both */
void	rr(t_carrier *pigeons)
{
	if (pigeons->head_a)
		ra(pigeons);
	if (pigeons->head_b)
		rb(pigeons);
}
