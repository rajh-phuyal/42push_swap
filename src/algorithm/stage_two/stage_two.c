/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:24:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/18 22:00:53 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	find_second_biggest(t_stack *head, int max)
{
	int	snd;

	snd = INT_MIN;
	while (head)
	{
		if (head->value >= snd && head->value < max)
			snd = head->value;
		if (head->value == (max - 1))
			break ;
		head = head->next;
	}
	return (snd);
}

void	send_back_to_a(t_carrier *pigeons, int moves, int dir)
{
	if (!pigeons->head_b)
		return ;
	else if (!pigeons->head_b->next)
	{
		pa(pigeons);
		return ;
	}
	while (moves)
	{
		if (dir == NORTH)
			rb(pigeons, 0);
		else
			rrb(pigeons, 0);
		moves--;
	}
	pa(pigeons);
	return ;
}

int	send_one_value(t_carrier *pigeons, int *dir)
{
	int			t_dir;
	int			moves;
	int			mv_big;
	int			mv_snd;
	static bool	was_big = false;

	mv_big = find_moves(pigeons, pigeons->max_b, dir, STACK_B);
	t_dir = *dir;
	mv_snd = find_moves(pigeons,
			find_second_biggest(pigeons->head_b, pigeons->max_b), dir, STACK_B);
	if (mv_big < mv_snd)
	{
		moves = mv_big;
		*dir = t_dir;
	}
	else
		moves = mv_snd;
	send_back_to_a(pigeons, moves, *dir);
}

void	send_back(t_carrier *pigeons)
{
	int	dir;

	dir = NORTH;
	if (!pigeons->head_b)
		return ;
	pigeons->size_b = stack_size(pigeons->head_b);
	while (pigeons->head_b)
	{
		rollback(pigeons, pigeons->head_b, STACK_B);
		send_one_value(pigeons, &dir);
		pigeons->size_b--;
	}
}
