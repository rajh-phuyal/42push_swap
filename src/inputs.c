/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:32:21 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/03 18:08:13 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/push_swap.h"

int	clean_inputs(int count, char **numbers)
{
	int	i;
	int	save;
	
	i = 1;
	while (i < count)
	{
		save = ft_atoi(numbers[i]);
		if (!save)
		{
			ft_printf("Error\n");
			return (1);
		}
		ft_printf("  %s\n", numbers[i]);
		i++;
	}
	return (0);
}