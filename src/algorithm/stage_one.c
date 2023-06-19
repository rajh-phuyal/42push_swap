/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 20:35:08 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_for_pause(t_carrier *pigeons)
{
	return ;
}

void	go_north(t_carrier *pigeons, int moves)
{
	if (!pigeons->head_a->next)
		pb(pigeons);
	while (moves--)
		ra(pigeons, 0);
	pb(pigeons);
	return ;
}

void	go_south(t_carrier *pigeons, int moves)
{
	if (!pigeons->head_a->next)
		pb(pigeons);
	while (moves--)
		rra(pigeons, 0);
	pb(pigeons);
	return ;
}

void	send_evens(t_carrier *pigeons, int count)
{
	int	dir;
	int	moves;

	dir = NORTH;
	moves = 0;
	while (count)
	{
		moves = find_moves_in_dir(pigeons, pigeons->min_even, &dir);
		if (dir == NORTH)
			go_north(pigeons, moves);
		else
			go_south(pigeons, moves);
		count--;
		rollback(pigeons, pigeons->head_a);
		check_for_pause(pigeons);
	}
}

void	send_odds(t_carrier *pigeons, int count)
{
	int	dir;
	int	moves;

	moves = 0;
	while (count)
	{
		moves = find_moves_in_dir(pigeons, pigeons->max_odd, &dir);
		if (dir == NORTH)
			go_north(pigeons, moves);
		else
			go_south(pigeons, moves);
		count--;
		rollback(pigeons, pigeons->head_a);
		check_for_pause(pigeons);
	}
}
