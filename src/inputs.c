/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:32:21 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/06 21:03:23 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	check_int_range(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (len == 10 && !ft_strncmp(str, "2147483647", len))
		return (true);
	else
		return (false)
	if (len == 11 && !ft_strncmp(str, "-2147483648", len))
		return (true);
	else
		return (false);
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
				&& check_int_range(numbers[i]))
			i++;
		else
		{
			ft_printf("Error\n");
			return (0);
		}
	}
	return (1);
}
