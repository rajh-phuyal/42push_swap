/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/11 20:07:07 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	case_for_rr(t_carrier *pigeons, int moves, int dir, bool is_rr)
{
	if (is_rr)
	{
		if (moves > 0 && dir == NORTH)
		{
			rr(pigeons);
			return (1);
		}
		else
			rb(pigeons, 0);
	}
	return (0);
}

void	go(t_carrier *pigeons, int moves, int dir, bool is_rr)
{
	if (!pigeons->head_a)
		return ;
	else if (!pigeons->head_a->next)
	{
		pb(pigeons);
		return ;
	}
	moves -= case_for_rr(pigeons, moves, dir, is_rr);
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

int	send_two_families(t_carrier *pigeons, int first, int second, int *dir)
{
	int			which;
	int			moves;
	t_stack		*node;
	static bool	is_rr = 0;

	node = node_to_send(pigeons, first, second, dir);
	if (!node)
		return (0);
	which = node->family;
	moves = find_moves(pigeons, node->value, dir);
	go(pigeons, moves, *dir, is_rr);
	rollback(pigeons, pigeons->head_a, STACK_A);
	is_rr = 1 - ((which % ((pigeons->families % 2 != 0) + 1) == 0));
	return (1);
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
	while (pigeons->head_a)
	{
		if (family == pigeons->families - 2)
			break ;
		if (count < (pigeons->siblings * 2))
		{
			if (!send_two_families(pigeons, family, family + 1, &dir))
				family++;
			count++;
		}
		else
			count = 0;
	}
}
