/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:32:21 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/02 20:51:30 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	clean_inputs(int count, char **numbers)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!ft_atoi(numbers[i]))
		{
			ft_printf("Error\n");
			return (1);
		}
		else
			ft_printf("  %s\n", numbers[i]);
		i++;
	}
	return (0);
}