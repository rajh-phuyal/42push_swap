/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/23 23:41:26 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_carrier	pigeons;

	pigeons.head_a = NULL;
	pigeons.head_b = NULL;
	pigeons.argv = NULL;
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (write(2, "Error\n", 6) - 6);
		argv = ft_split(argv[1], ' ');
		argc = ft_split_len(argv);
		pigeons.argv = argv;
	}
	if (argc > 1)
	{
		if (!clean_input(argc, argc, argv, &pigeons) || \
			is_stack_sorted(pigeons.head_a, ASC))
			return (free_pigeons(&pigeons));
		the_sorting_portal(&pigeons);
		free_pigeons(&pigeons);
	}
	return (0);
}


// int	handel_single_arg(t_carrier *pigeons, char **argv)
// {
// 	if (ft_strlen(argv[1]) == 0 || ft_empty_str(argv[1]))
// 		return (write(2, "Error\n", 6) - 6);
// 	pigeons->argv = ft_split(argv[1], ' ');
// 	if (!pigeons->argv || ft_split_len(pigeons->argv) <= 1)
// 		return (0);
// 	else
// 		return (1);
// }

// int	main(int argc, char **argv)
// {
// 	t_carrier	pigeons;

// 	pigeons.head_a = NULL;
// 	pigeons.head_b = NULL;
// 	pigeons.argv = NULL;
// 	if (argc == 2)
// 	{
// 		if (!handel_single_arg(&pigeons, argv))
// 			return (free_pigeons(&pigeons));
// 		argv = pigeons.argv;
// 		argc = ft_split_len(pigeons.argv);
// 	}
// 	if (argc > 1)
// 	{
// 		if (!clean_input(argc, argc, argv, &pigeons))
// 			return (free_pigeons(&pigeons));
// 		if (is_stack_sorted(pigeons.head_a, ASC))
// 			return (free_pigeons(&pigeons));
// 		the_sorting_portal(&pigeons);
// 		free_pigeons(&pigeons);
// 	}
// 	return (0);
// }