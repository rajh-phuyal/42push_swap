/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/25 21:53:38 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	special_parcing(t_carrier *pigeons, char **argv, int *argc)
{
	(void)argc;
	if (!ft_strlen(argv[1]) || ft_emptystr(argv[1]))
		return (write(2, "Error\n", 6) - 6);
	pigeons->argv = ft_split(argv[1], ' ');
	*argc = ft_splitlen(pigeons->argv);
	if (!pigeons->argv)
		return (0);
	if (*argc == 1)
	{
		if (!validate_input(ft_atoi(pigeons->argv[0]), pigeons->argv[0]))
			return (write(2, "Error\n", 6) - 6);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_carrier	pigeons;

	pigeons.head_a = NULL;
	pigeons.head_b = NULL;
	pigeons.argv = NULL;
	if (argc == 2)
	{
		if (!special_parcing(&pigeons, argv, &argc))
			return (free_pigeons(&pigeons));
		argv = pigeons.argv;
	}
	if (argc > 1)
	{
		if (!clean_input(argc, argc, argv, &pigeons) || \
			is_stack_sorted(pigeons.head_a))
			return (free_pigeons(&pigeons));
		the_sorting_portal(&pigeons);
	}
	free_pigeons(&pigeons);
	return (0);
}
