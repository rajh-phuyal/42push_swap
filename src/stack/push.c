/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:55:04 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/12 20:26:33 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* pushes the top of the stack b to top of the stack a */
void	pa(t_carrier *pigeons)
{
	if (!pigeons->head_b)
		return ;
	pigeons->head_a = push(pigeons->head_b->value, pigeons->head_a);
	pigeons->head_b = pop(pigeons->head_b);
	ft_printf("pa\n");
}

/* pushes the top of the stack a to top of the stack b */
void	pb(t_carrier *pigeons)
{
	if (!pigeons->head_a)
		return ;
	pigeons->head_b = push(pigeons->head_a->value, pigeons->head_b);
	pigeons->head_a = pop(pigeons->head_a);
	if (!pigeons->tail_b)
		pigeons->tail_b = pigeons->head_b;
	ft_printf("pb\n");
}
