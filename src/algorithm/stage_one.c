/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/02 15:17:03 by rphuyal          ###   ########.fr       */
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

t_stack	*which_node_to_send(t_carrier *pigeons)
{

}
void	send_to_b(t_carrier *pigeons)
{
	int	val;
	int	dir;
	int	moves;
	int	family;
	t_stack *node;

	dir = NORTH;
	family = malloc(sizeof(int) * pigeons->families);
	while (pigeons->size)
	{
		node = which_node_to_send(pigeons);
		// send two chunks of two families to b
		// moves = find_moves(pigeons, pigeons->min_a, &dir);
		go(pigeons, moves, dir);
		if (family % 2 != 0)
			rb(pigeons, 0);
		pigeons->size--;
		rollback(pigeons, pigeons->head_a, STACK_A);
	}
}
