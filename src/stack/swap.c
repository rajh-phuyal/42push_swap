/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:54:53 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/13 15:55:33 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* swap the values of the first two nodes of the stack a */
void	sa(t_carrier *pigeons, int redirected)
{
	int	temp;

	if (!pigeons->head_a->next)
		return ;
	temp = pigeons->head_a->value;
	pigeons->head_a->value = (pigeons->head_a->next)->value;
	(pigeons->head_a->next)->value = temp;
	if (!redirected)
		ft_printf("sa\n");
}

/* swap the values of the first two nodes of the stack b */
void	sb(t_carrier *pigeons, int redirected)
{
	int	temp;

	if (!pigeons->head_b->next)
		return ;
	temp = pigeons->head_b->value;
	pigeons->head_b->value = (pigeons->head_b->next)->value;
	(pigeons->head_b->next)->value = temp;
	if (!redirected)
		ft_printf("sb\n");
}

/* call both */
void	ss(t_carrier *pigeons)
{
	if (!pigeons->head_a->next)
		sa(pigeons, 1);
	if (!pigeons->head_b->next)
		sb(pigeons, 1);
	ft_printf("ss\n");
}
