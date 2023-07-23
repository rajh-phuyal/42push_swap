/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:56:01 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/23 16:28:01 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	manage_consecutive_snd(t_carrier *pigeons, int snd_count)
{
	int	rot;

	rot = snd_count;
	if (snd_count > 1)
	{
		while (rot)
		{
			ra(pigeons, 0);
			rot--;
		}
	}
	pa(pigeons);
	printf("snd_count: %d\n", snd_count);
	if (snd_count == 1)
		sa(pigeons, 0);
	else
	{
		sa(pigeons, 0);
		while (snd_count--)
			rra(pigeons, 0);
	}
}

void	find_place_instack(t_carrier *pigeons, bool c_snd, bool l_snd)
{
	static int	snd_count = 0;

	if (!c_snd && !l_snd)
		pa(pigeons);
	else if (c_snd && !l_snd)
	{
		pa(pigeons);
	}
	else if (c_snd && l_snd)
	{
		snd_count++;
		pa(pigeons);
	}
	else if (!c_snd && l_snd)
	{
		manage_consecutive_snd(pigeons, snd_count);
		snd_count = 0;
	}
}
