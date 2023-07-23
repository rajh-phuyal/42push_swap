/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_one.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:42 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/23 23:59:42 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

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

	node = NULL;
	least = INT_MAX;
	head = pigeons->head_a;
	while (head)
	{
		if (head->family == first || head->family == second)
		{
			moves = find_moves(pigeons, head->value, dir, STACK_A);
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
	static bool	is_rr = false;

	node = node_to_send(pigeons, first, second, dir);
	if (!node)
	{
		if (second == pigeons->families - 3 && is_rr)
		{
			rb(pigeons, 0);
			is_rr = false;
		}
		return (0);
	}
	which = node->family;
	moves = find_moves(pigeons, node->value, dir, STACK_A);
	go(pigeons, moves, *dir, is_rr);
	rollback(pigeons, pigeons->head_a, STACK_A);
	is_rr = true - (which % 2 != 0);
	return (1);
}

void	send_to_b(t_carrier *pigeons, int first, int second)
{
	int		dir;
	int		count;

	count = 0;
	dir = NORTH;
	while (true)
	{
		if (second >= pigeons->families - 2)
			break ;
		if (count <= (pigeons->siblings * 2))
		{
			if (!send_two_families(pigeons, first, second, &dir))
			{
				first += 2;
				second += 2;
				continue ;
			}
			count++;
			pigeons->size_a--;
		}
		else
			count = 0;
	}
	send_last_two(pigeons, first, second, &dir);
}
