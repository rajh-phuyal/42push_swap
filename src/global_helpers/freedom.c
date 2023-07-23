/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 21:49:56 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/23 21:59:32 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_argv(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
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
	if (pigeons->argv)
	{
		free_argv(pigeons->argv);
		free(pigeons->argv);
	}
	return (0);
}
