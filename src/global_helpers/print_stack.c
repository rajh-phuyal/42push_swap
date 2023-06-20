/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:55:31 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/20 00:49:02 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *head)
{
	if (!head)
		ft_printf(" Nothing here. 🤷\n");
	while (head)
	{
		ft_printf("\t%i\n", head->value);
		head = head->next;
	}
}
