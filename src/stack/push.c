/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:55:04 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/26 22:09:28 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* pushes the top of the stack b to top of the stack a */
void	pa(t_carrier *pigeons)
{
	t_stack	*temp;

	if (!pigeons->head_b)
		return ;
	pigeons->head_a = push(pigeons->head_b->value, pigeons->head_b->family, pigeons->head_a);
	pigeons->head_b = pop(pigeons->head_b);
	if (!pigeons->tail_a)
		pigeons->tail_a = pigeons->head_a;
	else
	{
		temp = pigeons->head_a;
		while (temp)
		{
			if (!temp->next)
				pigeons->tail_a = temp;
			temp = temp->next;
		}
	}
	ft_printf("pa\n");
}

/* pushes the top of the stack a to top of the stack b */
void	pb(t_carrier *pigeons)
{
	t_stack	*temp;

	if (!pigeons->head_a)
		return ;
	pigeons->head_b = push(pigeons->head_a->value, pigeons->head_a->family, pigeons->head_b);
	pigeons->head_a = pop(pigeons->head_a);
	if (!pigeons->tail_b)
		pigeons->tail_b = pigeons->head_b;
	else
	{
		temp = pigeons->head_b;
		while (temp)
		{
			if (!temp->next)
				pigeons->tail_b = temp;
			temp = temp->next;
		}
	}
	ft_printf("pb\n");
}
