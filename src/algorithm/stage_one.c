/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/21 20:48:08 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pause_stack(t_carrier *pigeons, char sending)
{
	static int	rotaions = 0;

	if (sending == 'O' || sending == 'E')
	{
		rb(pigeons, 0);
		rotaions++;
	}
	else
	{
		while (rotaions)
		{
			rrb(pigeons, 0);
			rotaions--;
		}
	}
}

void	go_north(t_carrier *pigeons, int moves)
{
	if (!pigeons->head_a || !pigeons->head_a->next)
	{
		pb(pigeons);
		return ;
	}
	while (moves--)
		ra(pigeons, 0);
	pb(pigeons);
	return ;
}

void	go_south(t_carrier *pigeons, int moves)
{
	if (!pigeons->head_a || !pigeons->head_a->next)
	{
		pb(pigeons);
		return ;
	}
	while (moves--)
		rra(pigeons, 0);
	pb(pigeons);
	return ;
}

int	which(t_carrier *pigeons)
{
	t_stack *head;
	int		least;
	int		moves;
	int		index;

	which(head)
	{
		if (head->value <= pigeons->range[0])
		{
			moves = find_moves(pigeons, head->value, 0);
			if (moves < least)
				index = head->index;
		}
		head = head->next;
	}
	return (index);
}

void	send_evens(t_carrier *pigeons, int count)
{
	int	dir;
	int	val;
	int	moves;
	int	rotaions;

	dir = NORTH;
	while (count)
	{
		if (find_moves(pigeons, pigeons->min_even, &dir) < \
			find_moves(pigeons, pigeons->max_even, &dir))
			val = pigeons->min_even;
		else
			val = pigeons->max_even;
		moves = find_moves(pigeons, val, &dir);
		if (dir == NORTH)
			go_north(pigeons, moves);
		else
			go_south(pigeons, moves);
		count--;
		pigeons->size--;
		if (val == pigeons->max_even && count > 0)
			pause_stack(pigeons, 'E');
		rollback(pigeons, pigeons->head_a);
	}
	pause_stack(pigeons, 'R');
}

void	send_odds(t_carrier *pigeons, int count)
{
	int	dir;
	int	val;
	int	moves;

	dir = NORTH;
	moves = 0;
	while (count)
	{
		if (find_moves(pigeons, pigeons->min_odd, &dir) < \
			find_moves(pigeons, pigeons->max_odd, &dir))
			val = pigeons->min_odd;
		else
			val = pigeons->max_odd;
		moves = find_moves(pigeons, val, &dir);
		if (dir == NORTH)
			go_north(pigeons, moves);
		else
			go_south(pigeons, moves);
		count--;
		pigeons->size--;
		if (val == pigeons->min_odd && count > 0)
			pause_stack(pigeons, 'O');
		rollback(pigeons, pigeons->head_a);
	}
	pause_stack(pigeons, 'R');
}
