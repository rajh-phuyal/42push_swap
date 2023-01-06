/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:14:43 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/06 19:42:29 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!clean_inputs(argc, argv))
			return (0);
		ft_printf("OK\n");
	}
	else
		return (0);
}
