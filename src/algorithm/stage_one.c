/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/30 00:09:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	go(t_carrier *pigeons, int moves, int dir)
{
	if (!pigeons->head_a)
		return ;
	else if (!pigeons->head_a->next)
	{
		pb(pigeons);
		return ;
	}
	while (moves--)
	{
		if (dir == NORTH)
			ra(pigeons, 0);
		else
			rra(pigeons, 0);
	}
	pb(pigeons);
	return ;
}

void	send_to_b(t_carrier *pigeons)
{
	int	dir;
	int	moves;

	dir = NORTH;
	while (pigeons->size)
	{
		// if (find_moves(pigeons, pigeons->min_a, &dir) < \
		// 	find_moves(pigeons, pigeons->max_a, &dir))
		// 	val = pigeons->min_a;
		// else
		// 	val = pigeons->max_a;
		// moves = find_moves(pigeons, val, &dir);
		moves = find_moves(pigeons, pigeons->min_a, &dir);
		go(pigeons, moves, dir);
		pigeons->size--;
		// if (val == pigeons->max_even && count > 0)
		// 	pause_stack(pigeons, 'E');
		rollback(pigeons, pigeons->head_a, STACK_A);
	}
}
