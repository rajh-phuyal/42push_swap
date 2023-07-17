/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:55:31 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/17 21:22:19 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	print_stack(t_stack *head)
{
	if (!head)
		ft_printf(" Nothing here. 🤷\n");
	while (head)
	{
		ft_printf("__________________________\n");
		ft_printf("VALUE   : %i\n", head->value);
		ft_printf("FAMILY  : %i\n", head->family);
		ft_printf("__________________________\n");
		head = head->next;
	}
}
