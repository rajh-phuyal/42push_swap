/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:32:21 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/12 01:47:46 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* standard atoi return the int edges if the value exiceeds the int range,
if the atoi returns int min or int max, we can use the string used for atoi 
to validate if endeed the string contained int min or int max.*/
bool	int_within_range(int num, char *str)
{
	if (ft_strlen(str) >= 10)
	{
		if (num >= INT_MAX && ft_strncmp(str, "2147483647", 11))
			return (false);
		else if (num <= INT_MIN && ft_strncmp(str, "-2147483648", 12))
			return (false);
		else
			return (true);
	}
	else
		return (true);
}

/* caution with the char that might be mixed up between digits,
since atoi returns the first int it discovers in a given string
leaving the remaining chars that comes after*/
bool	no_random_chars(char *str)
{
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

/* well, check for duplicate ints*/
int	duplicate_inputs(t_carrier *pigeons)
{
	t_stack	*head;
	t_stack	*iterator;

	head = pigeons->head_a;
	while (head)
	{
		iterator = head->next;
		while (iterator)
		{
			if (head->value == iterator->value)
				return (ft_printf("Error\n") - 6);
			iterator = iterator->next;
		}
		head = head->next;
	}
	return (1);
}

/* Two in one function, validates the inputs while 
simultaneously creating stack a. All the input validation 
functions above are called from here for each argument*/
int	clean_inputs(int i, int count, char **numbers, t_carrier *pigeons)
{
	int		save;
	t_stack	*node;

	node = NULL;
	while (i < count)
	{
		save = ft_atoi(numbers[i]);
		if ((save || !ft_strncmp(numbers[i], "0", ft_strlen(numbers[i]))) \
		&& int_within_range(save, numbers[i]) && no_random_chars(numbers[i]))
		{
			node = push(save, node);
			if (i == 1)
				pigeons->tail_a = node;
			if (i + 1 == count)
				pigeons->head_a = node;
			i++;
		}
		else
		{
			if (node)
				pigeons->head_a = node;
			return (ft_printf("Error\n") - 6);
		}
	}
	return (duplicate_inputs(pigeons));
}
