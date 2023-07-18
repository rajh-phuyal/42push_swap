/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:01:35 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/18 20:38:35 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	three_or_less(t_carrier *pigeons, t_stack *head, t_stack *tail, int size)
{
	if (size == 2)
		sa(pigeons, 0);
	else if (head->value > head->next->value && head->value > tail->value)
	{
		if (head->next->value < tail->value)
			ra(pigeons, 0);
		else if (head->next->value > tail->value)
		{
			sa(pigeons, 0);
			rra(pigeons, 0);
		}
	}
	else if (head->next->value > head->value && head->next->value > tail->value)
	{
		if (head->value > tail->value)
			rra(pigeons, 0);
		else if (head->value < tail->value)
		{
			sa(pigeons, 0);
			ra(pigeons, 0);
		}
	}
	else if (head->value > head->next->value && \
	tail->value > (head->value && head->next->value))
		sa(pigeons, 0);
}

void    five_or_less(t_carrier *pigeons)
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
	three_or_less(pigeons, pigeons->head_a, pigeons->tail_a, pigeons->size_a);
	while (count)
	{
		pa(pigeons);
		count--;
	}
}

void	ten_or_less(t_carrier *pigeons)
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
	five_or_less(pigeons);
	while (count)
	{
		pa(pigeons);
		count--;
	}
}