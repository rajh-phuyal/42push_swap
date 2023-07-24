/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 04:08:40 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/24 13:06:30 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	execute_instruction(char *line, t_carrier *pigeons)
{
	if (!ft_strncmp(line, "sa", 3))
		sa(pigeons, 0);
	else if (!ft_strncmp(line, "sb", 3))
		sb(pigeons, 0);
	else if (!ft_strncmp(line, "ss", 3))
		ss(pigeons);
	else if (!ft_strncmp(line, "pa", 3))
		pa(pigeons);
	else if (!ft_strncmp(line, "pb", 3))
		pb(pigeons);
	else if (!ft_strncmp(line, "ra", 3))
		ra(pigeons, 0);
	else if (!ft_strncmp(line, "rb", 3))
		rb(pigeons, 0);
	else if (!ft_strncmp(line, "rr", 3))
		rr(pigeons);
	else if (!ft_strncmp(line, "rra", 4))
		rra(pigeons, 0);
	else if (!ft_strncmp(line, "rrb", 4))
		rrb(pigeons, 0);
	else if (!ft_strncmp(line, "rrr", 4))
		rrr(pigeons);
	else
		return (0);
	return (1);
}

void	listen_for_instructions(t_carrier *pigeons)
{
	char	*line;

	line = NULL;
	while (true)
	{
		line = get_next_line(0);
		if (!execute_instruction(line, pigeons))
		{
			ft_printf("Error\n");
			free(line);
			return ;
		}
		free(line);
		line = NULL;
	}
	free(line);
	if (is_stack_sorted(pigeons->head_a, ASC))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_printf("\n");
}

void	print_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		ft_printf("%s ", argv[i]);
		i++;
	}
	ft_printf("\n");
}

int	main(int argc, char **argv)
{
	t_carrier	pigeons;

	pigeons.head_a = NULL;
	pigeons.head_b = NULL;
	if (argc > 1)
	{
		print_args(argc, argv);
		printf("argc: %d\n", argc);
		if (!clean_input(argc, argc, argv, &pigeons))
			return (free_pigeons(&pigeons));
		listen_for_instructions(&pigeons);
		return (free_pigeons(&pigeons));
	}
	return (0);
}
