/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 02:15:59 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


int	main(int argc, char **argv)
{
	t_carrier	*pigeons;

	pigeons = (t_carrier *)malloc(sizeof(t_carrier));
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_split_len(argv);
	}
	if (argc > 1)
	{
		if (!clean_input(argc, argc, argv, pigeons) || is_stack_sorted(pigeons))
			return (free_pigeons(pigeons));
		reset_all_limits(pigeons);
		find_min_max(pigeons, pigeons->head_a, 0);
		ft_print_list(pigeons);
		the_sorting_portal(pigeons);
		free_pigeons(pigeons);
	}
	else
		return (0);
}