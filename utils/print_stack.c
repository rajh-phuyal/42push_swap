/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:01:33 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 02:07:45 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack *head)
{
	while (head)
	{
		ft_printf("%i\n", head->value);
		head = head->next;
	}
}

void	ft_print_list(t_carrier *pigeons)
{
	t_stack *current_a = pigeons->head_a;
	t_stack *current_b = pigeons->head_b;

	// print min and max values
	printf(SBLUE"╒≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡╕\n"RESET);
	printf(GREEN"     MIN EVEN  %d | MAX EVEN %d\n"RESET, pigeons->min_even, pigeons->max_even);
	printf(GREEN"     MIN ODD   %d | MAX ODD : %d\n"RESET, pigeons->min_odd, pigeons->max_odd);
	printf(SBLUE"╘≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡≡╛\n"RESET);
	// print stack A
	printf(YELLOW"╔═══════════════╗\n"RESET);
	printf(PURPLE"        A        \n"RESET);
	if (!current_a)
		printf (RED"     EMPTY!!\n" RESET);
	while (current_a)
	{
		printf (SALMON" INDEX %d\n", current_a->index);
		printf (GREEN" CURRENT_A NUM %d\n"RESET, current_a->value);
		if (!current_a->next)
			printf(CYAN" NEXT - NULL\n"RESET);
		else
			printf (CYAN" NEXT VALUE - %d\n"RESET, current_a->next->value);
		if (current_a->next)
			printf (YELLOW"=================\n"RESET);
		current_a = current_a->next;
	}
	printf (YELLOW"╚═══════════════╝\n"RESET);

	// print stack B
	printf (YELLOW"╔═══════════════╗\n"RESET);
	printf (PURPLE"        B        \n"RESET);
	if (!current_b)
		printf (RED"     EMPTY!!\n"RESET);
	while (current_b)
	{
		printf(GREEN" CURRENT_B NUM %d\n"RESET, current_b->value);
		if (!current_b->next)
			printf(CYAN" NEXT - NULL\n"RESET);
		else
			printf (CYAN" NEXT VALUE - %d\n"RESET, current_b->next->value);
		if (current_b->next)
			printf (YELLOW"=================\n"RESET);
		current_b = current_b->next;
	}
	printf (YELLOW"╚═══════════════╝\n"RESET);
}