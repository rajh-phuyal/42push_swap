/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:56:16 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/24 16:24:33 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_index(char **argv)
{
	if (!ft_strncmp(argv[0], "./push_swap", 12))
		return (1);
	else if (!ft_strnstr(argv[0], "./push_swap", ft_strlen(argv[0])))
		return (1);
	else
		return (0);
}

