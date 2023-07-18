/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:48:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/18 22:06:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

int	mean_of_family(t_stack *head, int family)
{
	int	sum;
	int	count;

	sum = 0;
	count = 0;
	while (head)
	{
		if (head->family == family)
		{
			sum += head->value;
			count++;
		}
		head = head->next;
	}
	if (count == 0)
		return (0);
	return (sum / count);
}

int	send_one_family(t_carrier *pigeons, int fam, int mid, int *dir)
{
	int			val;
	int			moves;
	t_stack		*node;
	static bool	is_rr = false;

	node = node_to_send(pigeons, fam, 0, dir);
	if (!node)
		return (0);
	val = node->value;
	moves = find_moves(pigeons, node->value, dir, STACK_A);
	go(pigeons, moves, *dir, is_rr);
	rollback(pigeons, pigeons->head_a, STACK_A);
	is_rr = true - (val > mid);
	return (1);
}

void	send_last_two(t_carrier *pigeons, int first, int second, int *dir)
{
	int		count;
	int		mid;
	t_stack	*head;

	mid = mean_of_family(pigeons->head_a, first);
	count = 0;
	while (count <= pigeons->siblings)
	{
		if (!send_one_family(pigeons, first, mid, dir))
			break ;
		count++;
	}
	mid = mean_of_family(pigeons->head_a, second);
	pigeons->size_a = stack_size(pigeons->head_a);
	while (pigeons->size_a > 4)
	{
		if (!send_one_family(pigeons, second, mid, dir))
			break ;
		pigeons->size_a--;
	}
	if (is_stack_sorted(pigeons->head_a, ASC))
		return ;
	rollback(pigeons, pigeons->head_a, STACK_A);
	sort_five(pigeons);
}
