/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/12 20:50:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	print_stack(t_stack *head)
// {
// 	while (head)
// 	{
// 		ft_printf("%i\n", head->value);
// 		head = head->next;
// 	}
// }

int	main(int argc, char **argv)
{
	t_carrier	*pigeons;

	pigeons = (t_carrier *)malloc(sizeof(t_carrier));
	if (argc > 1)
	{
		if (!clean_input(argc, argc, argv, pigeons) || is_stack_sorted(pigeons))
			return (free_pigeons(pigeons));
		free_pigeons(pigeons);
		ft_printf("INPUTS OK\n");
	}
	else
		return (0);
}

/*
ft_printf("Before\n");
		ft_printf("-----stack a --------\n");
		print_stack(pigeons->head_a);
		ft_printf("---------------------\n");
		rra(pigeons);
		ft_printf("After\n");
		ft_printf("-----stack a --------\n");
		print_stack(pigeons->head_a);
		ft_printf("---------------------\n");
		pb(pigeons);
		pb(pigeons);
		pb(pigeons);
		ft_printf("Before\n");
		ft_printf("-----stack b --------\n");
		print_stack(pigeons->head_b);
		ft_printf("---------------------\n");
		rrb(pigeons);
		ft_printf("After\n");
		ft_printf("-----stack b --------\n");
		print_stack(pigeons->head_b);
		ft_printf("---------------------\n");
*/