/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:54:56 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/18 22:09:30 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* pushes the bottom of the stack a to top of the stack a
shifting all the elements down one index. */
void	rra(t_carrier *pigeons, int redirected)
{
	t_stack	*temp;

	if (!pigeons->head_a)
		return ;
	temp = pigeons->head_a;
	while (temp)
	{
		if (!temp->next)
			pigeons->tail_a = temp;
		else if (!(temp->next)->next)
		{
			temp->next = NULL;
			pigeons->tail_a->next = pigeons->head_a;
			pigeons->head_a = pigeons->tail_a;
			pigeons->tail_a = temp;
		}
		temp = temp->next;
	}
	if (!redirected)
		ft_printf("rra\n");
}

/* pushes the bottom of the stack b to top of the stack b
shifting all other elements down one index. */
void	rrb(t_carrier *pigeons, int redirected)
{
	t_stack	*temp;

	if (!pigeons->head_b)
		return ;
	temp = pigeons->head_b;
	while (temp)
	{
		if (!temp->next)
			pigeons->tail_b = temp;
		else if (!(temp->next)->next)
		{
			temp->next = NULL;
			pigeons->tail_b->next = pigeons->head_b;
			pigeons->head_b = pigeons->tail_b;
			pigeons->tail_b = temp;
		}
		temp = temp->next;
	}
	if (!redirected)
		ft_printf("rrb\n");
}

/* call both */
void	rrr(t_carrier *pigeons)
{
	if (pigeons->head_a)
		rra(pigeons, 1);
	if (pigeons->head_b)
		rrb(pigeons, 1);
	ft_printf("rrr\n");
}
