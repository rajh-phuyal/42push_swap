/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:29:37 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/27 03:32:01 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	find_species(t_carrier *pigeons)
{
	t_stack	*head;

	pigeons->even_count = 0;
	pigeons->odd_count = 0;
	head = pigeons->head_a;
	while (head)
	{
		if (head->value % 2 == 0)
			pigeons->even_count++;
		else
			pigeons->odd_count++;
		head = head->next;
	}
}

int		find_index_arr(int *arr, int size, int to_find)
{
	if (size == 0)
		return (-1);
	if (arr[size - 1] == to_find)
		return (size - 1);
	return (find_index_arr(arr, size - 1, to_find));
}


void	find_even_siblings(t_carrier *pigeons, t_stack *head, int *arr, int blocks)
{
	int	max_pos;
	int	min_pos;
	int my_index;
	int	max_sibling;

	max_sibling = ;
	max_pos = find_index_arr(arr, pigeons->size, pigeons->max_even);
	min_pos = find_index_arr(arr, pigeons->size, pigeons->min_even);
	while (head)
	{
		if (head->value % 2 == 0)
		{
			if (head->value == pigeons->max_even)
				head->family = blocks;
			else if (head->value == pigeons->min_even)
				head->family = 0;
			else
			{
				my_index = find_index_arr(arr, pigeons->size, head->value);
				if (max_pos - my_index < my_index - min_pos)
					head->family = blocks;
				else
					head->family = curr_fam;
			}
		}
		head = head->next;
	}
}

void	find_odd_siblings(t_carrier *pigeons, t_stack *head, int *arr, int blocks)
{
	int	curr_fam;
	int	max_pos;
	int	min_pos;
	int my_index;

	curr_fam = 0;
	max_pos = find_index_arr(arr, pigeons->size, pigeons->max_odd);
	min_pos = find_index_arr(arr, pigeons->size, pigeons->min_odd);
	while (head)
	{
		if (head->value % 2 == 0)
		{
			if (head->value == pigeons->max_odd)
				head->family = blocks;
			else if (head->value == pigeons->min_odd)
				head->family = 0;
			else
			{
				my_index = find_index_arr(arr, pigeons->size, head->value);
				if (max_pos - my_index < my_index - min_pos)
					head->family = blocks;
				else
					head->family = 0;
			}
		}
		head = head->next;
	}
}

int	find_diff_range(t_carrier *pigeons, t_stack *head, int *arr)
{
	int even_blocks;
	int odd_blocks;
	int	min_siblings;

	min_siblings = 3;
	even_blocks = pigeons->even_count / min_siblings +
				(pigeons->even_count % min_siblings != 0);
	odd_blocks = pigeons->odd_count / min_siblings +
				(pigeons->odd_count % min_siblings != 0);
	ft_printf("min_siblings: %i\n", min_siblings);
	ft_printf("even_count: %i\n", pigeons->even_count);
	ft_printf("odd_count: %i\n", pigeons->odd_count);
	ft_printf("first op even: %i\n", pigeons->even_count / min_siblings);
	ft_printf("first op odd: %i\n", pigeons->odd_count / min_siblings);
	ft_printf("even_blocks: %i\n", even_blocks);
	ft_printf("odd_blocks: %i\n", odd_blocks);
	find_even_siblings(pigeons, head, arr, even_blocks, min_siblings);
	find_odd_siblings(pigeons, head, arr, odd_blocks, min_siblings);
	return (1);
}

void	find_siblings(t_carrier *pigeons)
{
	int *sorted;

	sorted = map_and_sort(pigeons->head_a, pigeons->size);
	if (!sorted)
		return ;
	find_diff_range(pigeons, pigeons->head_a, sorted);
	free(sorted);
}
