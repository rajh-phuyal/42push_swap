/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:42:59 by rphuyal           #+#    #+#             */
/*   Updated: 2023/01/02 20:16:59 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/* 
structure for nodes to contain a pointer to the
next and previous nodes and a value.
*/
typedef struct double_link
{
	int					value;
	struct double_link	*previous;
	struct double_link	*next;
}	t_double_link;

typedef struct stack
{
	int					size;
	struct double_link	*head;
	struct double_link	*tail;
} t_stack;

typedef struct carrier
{
	struct stack	*stackA;
	struct stack	*stackB;
} t_carrier;

/* main */
int	main(int argc, char **argv);

/* treating the inputs */

#endif