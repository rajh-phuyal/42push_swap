/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/10 20:29:55 by rphuyal          ###   ########.fr       */
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

t_stack	*node_to_send(t_carrier *pigeons, int first, int second, int *dir)
{
	int		moves;
	int		least;
	t_stack	*node;
	t_stack	*head;

	least = 1000;
	node = NULL;
	head = pigeons->head_a;
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

void	check_for_rr(t_stack *pigeons);

int	send_two_families(t_carrier *pigeons, int first, int second, int *dir)
{
	int			which;
	int			moves;
	t_stack		*node;

	node = node_to_send(pigeons, first, second, dir);
	which = node->family;
	moves = find_moves(pigeons, node->value, dir);
	go(pigeons, moves, *dir);
	rollback(pigeons, pigeons->head_a, STACK_A);
	return (which);
}

void	send_to_b(t_carrier *pigeons)
{
	int		dir;
	int		count;
	int		moves;
	int		family;
	t_stack	*node;

	count = 0;
	family = 0;
	dir = NORTH;
	while (pigeons->size)
	{
		if (!pigeons->head_a)
			break ;
		if (count < pigeons->siblings * 2)
		{
			if (send_two_families(pigeons, family, family + 1, &dir) % 2 == 0)
				rb(pigeons, 0);
			count++;
		}
		else
		{
			count = 0;
			family++;
		}
	}
}
