/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:01:35 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/24 17:05:16 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	sort_three(t_carrier *pigeons, int size)
{
	if (size == 2)
		sa(pigeons, 0);
	if ((pigeons->head_a->value > pigeons->head_a->next->value)
		&& pigeons->head_a->value > pigeons->tail_a->value)
		ra(pigeons, 0);
	if ((pigeons->head_a->next->value > pigeons->head_a->value)
		&& (pigeons->head_a->next->value > pigeons->tail_a->value))
		rra(pigeons, 0);
	if (pigeons->head_a->value > pigeons->head_a->next->value)
		sa(pigeons, 0);
}

void	sort_five(t_carrier *pigeons)
{
	int	moves;
	int	dir;
	int	count;

	pigeons->size_a = stack_size(pigeons->head_a);
	count = 0;
	while (pigeons->size_a > 3)
	{
		rollback(pigeons, pigeons->head_a, STACK_A);
		moves = find_moves(pigeons, pigeons->min_a, &dir, STACK_A);
		go(pigeons, moves, dir, false);
		pigeons->size_a--;
		count++;
	}
	sort_three(pigeons, pigeons->size_a);
	while (count)
	{
		pa(pigeons);
		count--;
	}
}

void	sort_ten(t_carrier *pigeons)
{
	int	moves;
	int	dir;
	int	count;

	pigeons->size_a = stack_size(pigeons->head_a);
	count = 0;
	while (pigeons->size_a > 5)
	{
		rollback(pigeons, pigeons->head_a, STACK_A);
		moves = find_moves(pigeons, pigeons->min_a, &dir, STACK_A);
		go(pigeons, moves, dir, false);
		pigeons->size_a--;
		count++;
	}
	sort_five(pigeons);
	while (count)
	{
		pa(pigeons);
		count--;
	}
}
