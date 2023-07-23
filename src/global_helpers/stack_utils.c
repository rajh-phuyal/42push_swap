/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:56:13 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/23 21:50:11 by rphuyal          ###   ########.fr       */
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

