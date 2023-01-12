/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/12 01:38:55 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* 
structure for nodes to contain a int
an a link to the next node
*/
typedef struct stack
{
	int				value;
	struct stack	*next;
}	t_stack;

/* keeps track of both stacks */
typedef struct carrier
{
	int				size_a;
	int				size_b;
	struct stack	*head_a;
	struct stack	*tail_a;
	struct stack	*head_b;
	struct stack	*tail_b;
}	t_carrier;

/* main */
int		main(int argc, char **argv);

/* cleaning the inputs*/
int		clean_inputs(int i, int count, char **numbers, t_carrier *pigeons);
bool	int_within_range(int num, char *str);
bool	no_random_chars(char *str);
int		duplicate_inputs(t_carrier *pigeons);

/* exit */
int		free_pigeons(t_carrier *pigeons);

/* basic stack operations */
int		is_stack_sorted(t_carrier *pigeons);
t_stack	*push(int num, t_stack *head);
t_stack	*pop(t_stack *head);
int		stack_size(t_stack *lst);

#endif
