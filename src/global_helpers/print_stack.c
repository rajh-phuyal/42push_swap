/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:55:31 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/27 02:25:37 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *head)
{
	if (!head)
		ft_printf(" Nothing here. 🤷\n");
	while (head)
	{
		if (head->value % 2 == 0)
		{
			ft_printf("\tVALUE: %i\n", head->value);
			ft_printf("\tFAMILY: %i\n", head->family);
		}
		head = head->next;
	}
}
