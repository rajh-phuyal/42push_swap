/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_and_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:31:28 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/26 15:59:28 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *arr, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] < pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void	quicksort_arr(int *arr, int low, int high)
{
	int	pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		quicksort_arr(arr, low, pi - 1);
		quicksort_arr(arr, pi + 1, high);
	}
}

int	*map_and_sort(t_stack *head, int size)
{
	int		i;
	int		*sorted;

	i = 0;
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
		return (NULL);
	while (head)
	{
		sorted[i++] = head->value;
		head = head->next;
	}
	quicksort_arr(sorted, 0, size - 1);
	return (sorted);
}