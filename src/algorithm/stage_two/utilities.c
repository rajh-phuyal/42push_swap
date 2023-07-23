/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:56:01 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/23 17:35:57 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/push_swap.h"

void	manage_last_snd(t_carrier *pigeons)
{
	int	rot;
	int	l_send;

	l_send = find_place_instack(pigeons, false, false, true);
	rot = l_send;
	if (l_send > 1)
	{
		while (rot)
		{
			ra(pigeons, 0);
			rot--;
		}
	}
	pa(pigeons);
	if (l_send == 1)
		sa(pigeons, 0);
	else
	{
		while (l_send)
		{
			rra(pigeons, 0);
			l_send--;
		}
	}
}

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
	if (snd_count == 1)
		sa(pigeons, 0);
	else
	{
		while (snd_count)
		{
			rra(pigeons, 0);
			snd_count--;
		}
	}
}

int	find_place_instack(t_carrier *pigeons, bool c_snd, bool l_snd, bool get)
{
	static int	snd_count = 0;

	if (c_snd)
		snd_count++;
	if (get)
		return (snd_count);
	if ((!c_snd && !l_snd))
		pa(pigeons);
	else if ((c_snd && l_snd) || (c_snd && !l_snd))
		pa(pigeons);
	else if (!c_snd && l_snd)
	{
		manage_consecutive_snd(pigeons, snd_count);
		snd_count = 0;
	}
	return (snd_count);
}
