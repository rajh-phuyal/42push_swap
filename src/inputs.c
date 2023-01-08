/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nexus <nexus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:32:21 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/08 23:40:19 by nexus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_int_range(int num, char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len >= 10)
	{
		if (num >= INT_MAX && ft_strncmp(str, "2147483647", len))
			return (false);
		else if (num <= INT_MIN && ft_strncmp(str, "-2147483648", len))
			return (false);
		else
			return (true);
	}
	else
		return (true);
}

int	clean_inputs(int count, char **numbers)
{
	int	i;
	int	save;

	i = 1;
	while (i < count)
	{
		save = ft_atoi(numbers[i]);
		ft_printf("save: %i \n", save);
		if ((save || !ft_strncmp(numbers[i], "0", ft_strlen(numbers[i]))) \
				&& check_int_range(save, numbers[i]))
			i++;
		else
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
