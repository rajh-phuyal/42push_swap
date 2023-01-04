/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:32:21 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/04 21:04:51 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	clean_inputs(int count, char **numbers)
{
	int	i;
	int	save;

	i = 1;
	while (i < count)
	{
		save = ft_atoi(numbers[i]);
		if (save || ft_strncmp(numbers[i], "0", ft_strlen(numbers[i])) == 0)
		{
			ft_printf(" %s\n", numbers[i]);
			i++;
		}
		else
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
