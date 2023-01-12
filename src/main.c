/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/12 01:58:47 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_carrier	*pigeons;

	pigeons = (t_carrier *)malloc(sizeof(t_carrier));
	if (argc > 1)
	{
		if (!clean_inputs(1, argc, argv, pigeons) || is_stack_sorted(pigeons))
			return (free_pigeons(pigeons));
		pigeons->size_a = stack_size(pigeons->head_a);
		while (pigeons->head_a)
		{
			ft_printf("values : %i\n", pigeons->head_a->value);
			pigeons->head_a = pigeons->head_a->next;
		}
		free_pigeons(pigeons);
		ft_printf("INPUTS OK\n");
	}
	else
		return (0);
}
