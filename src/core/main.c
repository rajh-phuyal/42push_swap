/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/20 00:42:01 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"


int	main(int argc, char **argv)
{
	t_carrier	*pigeons;

	pigeons = (t_carrier *)malloc(sizeof(t_carrier));
	pigeons->head_a = NULL;
	pigeons->head_b = NULL;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argc = ft_split_len(argv);
	}
	if (argc > 1)
	{
		if (!clean_input(argc, argc, argv, pigeons) || is_stack_sorted(pigeons))
			return (free_pigeons(pigeons));
		the_sorting_portal(pigeons);
		free_pigeons(pigeons);
	}
	return (0);
}
