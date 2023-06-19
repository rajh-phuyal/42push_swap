/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 16:26:30 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	check_for_pause(t_carrier *pigeons)
{
	return ;
}

void	go_north(t_carrier *pigeons, int moves)
{
	return ;
}

void	go_south(t_carrier *pigeons, int moves)
{
	return ;
}

void	send_evens(t_carrier *pigeons, int *count)
{
	int	dir;
	int	moves;

	dir = NORTH;
	moves = 0;
	while (*count)
	{
		moves = find_moves_in_dir(pigeons, pigeons->min_even, &dir);
		if (dir == NORTH)
			go_north(pigeons, moves);
		else
			go_south(pigeons, moves);
		*count--;
		rollback(pigeons, pigeons->head_a, 0);
		check_for_pause(pigeons);
	}
}

void	send_odds(t_carrier *pigeons, int *count)
{
	int	dir;
	int	moves;

	moves = 0;
	while (*count)
	{
		moves = find_moves_in_dir(pigeons, pigeons->min_odd, &dir);
		if (dir == NORTH)
			go_north(pigeons, moves);
		else
			go_south(pigeons, moves);
		*count--;
		rollback(pigeons, pigeons->head_a, 0);
		check_for_pause(pigeons);
	}
}
