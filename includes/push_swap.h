/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/04 21:05:51 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* 
structure for nodes to contain a int
an a link to the next node
*/
typedef struct single_link
{
	int					value;
	struct single_link	*next;
}	t_single_link;

/* keeps track of contents of an inividual stack*/
typedef struct stack
{
	int					size;
	struct single_link	*head;
	struct single_link	*tail;
}	t_stack;

/* keeps track of both stacks */
typedef struct carrier
{
	struct stack	*stackA;
	struct stack	*stackB;
}	t_carrier;

/* main */
int	main(int argc, char **argv);

/* cleaning the inputs*/
int	clean_inputs(int count, char **numbers);

/* treating the inputs */

#endif
