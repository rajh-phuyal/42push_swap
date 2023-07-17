/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:56:13 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/17 13:44:35 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* get the stacksize for either stack*/
int	stack_size(t_stack *head)
{
	if (!head)
		return (0);
	else
		return (1 + stack_size(head->next));
}

/* check if the stack is sorted */
int	is_stack_sorted(t_stack *head, int order)
{
	int	ops;

	if (!head)
		return (0);
	while (head->next)
	{
		if (order == ASC)
			ops = (head->value > head->next->value);
		else if (order == DESC)
			ops = (head->value < head->next->value);
		else
			return (0);
		if (ops)
			return (0);
		head = head->next;
	}
	return (1);
}

/* push operaton on stack adds a new node on the top of a stack,
in this case, replacing the previous head with a new node which
points to the previous head. */
t_stack	*push(int num, int fam, t_stack *head)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = num;
	new_node->family = fam;
	new_node->next = head;
	return (new_node);
}

/* pop operaton on stack removes the node on the top of a stack. */
t_stack	*pop(t_stack *head)
{
	t_stack	*temp;

	temp = head->next;
	free(head);
	return (temp);
}

/* frees the both pigeons(from the cage called carrier) along with
the stack they were carrying */
int	free_pigeons(t_carrier *pigeons)
{
	t_stack	*temp;

	while (pigeons->head_a)
	{
		temp = (pigeons->head_a)->next;
		free(pigeons->head_a);
		pigeons->head_a = temp;
	}
	while (pigeons->head_b)
	{
		temp = (pigeons->head_b)->next;
		free(pigeons->head_b);
		pigeons->head_b = temp;
	}
	if (pigeons->sorted)
		free(pigeons->sorted);
	return (0);
}
