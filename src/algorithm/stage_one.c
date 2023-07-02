/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/02 19:22:03 by rphuyal          ###   ########.fr       */
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
	while (moves)
	{
		if (dir == NORTH)
			ra(pigeons, 0);
		else
			rra(pigeons, 0);
		moves--;
	}
	pb(pigeons);
	return ;
}

t_stack	*node_to_send(t_carrier *pigeons, t_stack *head, int first, int second, int *dir)
{
	int		moves;
	int		least;
	t_stack	*node;

	least = 1000;
	while (head)
	{
		if (head->family == first || head->family == second)
		{
			moves = find_moves(pigeons, head->value, dir);
			if (moves < least)
			{
				least = moves;
				node = head;
			}
		}
		head = head->next;
	}
	return (node);
}

void	send_to_b(t_carrier *pigeons)
{
	int	dir;
	int	count;
	int	moves;
	int	family;
	t_stack	*node;

	dir = NORTH;
	family = 0;
	count = 0;
	while (pigeons->size)
	{
		if (count < pigeons->siblings)
		{
			// send two chunks of two families to b
			node = node_to_send(pigeons, pigeons->head_a, family, family + 1, &dir);
			moves = find_moves(pigeons, node->value, &dir);
			go(pigeons, moves, dir);
			rollback(pigeons, pigeons->head_a, STACK_A);
			ft_printf("node->family: %d\n", node->family);
			if (node->family % 2 != 0)
		 		rb(pigeons, 0);
			ft_printf("here\n");
			count++;
		}
		else
		{
			count = 0;
			family++;
		}
	}
}
