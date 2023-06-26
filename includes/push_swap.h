/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/26 16:05:37 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define NORTH 1
# define SOUTH 2

/*
structure for nodes to contain a int
an a link to the next node
*/
typedef struct stack
{
	int				value;
	int				index;
	struct stack	*next;
}	t_stack;

/* keeps track of both stacks */
typedef struct carrier
{
	struct stack	*head_a;
	struct stack	*tail_a;
	struct stack	*head_b;
	struct stack	*tail_b;
	int				size;
	int				min_even;
	int				max_even;
	int				min_odd;
	int				max_odd;
	int				*range;
	int				odd_count;
	int				even_count;
	int				direction;
}	t_carrier;


/* main */
int		main(int argc, char **argv);

/* cleaning the inputs*/
bool	validate_input(int save, char *str);
bool	int_within_range(int num, char *str);
bool	no_random_chars(char *str);
int		duplicate_inputs(t_carrier *pigeons);
int		clean_input(int i, int count, char **numbers, t_carrier *pigeons);

/* exit */
int		free_pigeons(t_carrier *pigeons);

/* helpers */
void	print_stack(t_stack *head);
int		find_index(char **argv);
/* end */

/* stack */
/* basic stack operations */
int		stack_size(t_stack *lst);
int		is_stack_sorted(t_carrier *pigeons);
t_stack	*push(int num, t_stack *head);
t_stack	*pop(t_stack *head);
/* end */

/* provided operations to use on the two stack*/
/* swap */
void	sa(t_carrier *pigeons, int redirected);
void	sb(t_carrier *pigeons, int redirected);
void	ss(t_carrier *pigeons);

/* push */
void	pa(t_carrier *pigeons);
void	pb(t_carrier *pigeons);

/* rotate */
void	ra(t_carrier *pigeons, int redirected);
void	rb(t_carrier *pigeons, int redirected);
void	rr(t_carrier *pigeons);

/* reverse rotate */
void	rra(t_carrier *pigeons, int redirected);
void	rrb(t_carrier *pigeons, int redirected);
void	rrr(t_carrier *pigeons);
/* end */

/* algorithm */
void	the_sorting_portal(t_carrier *pigeons);
void	only_three(t_carrier *pigeons, t_stack *head, t_stack *tail, int size);
void	rollback(t_carrier *pigeons, t_stack *stack);
void	find_species(t_carrier *pigeons);
int		*find_ranges(t_carrier *pigeons);
int		find_position(t_stack *stack, int to_find);
int		find_moves(t_carrier *pigeons, int val, int *direction);
int		*map_and_sort(t_stack *head, int size);
void	send_evens(t_carrier *pigeons, int count);
void	send_odds(t_carrier *pigeons, int count);
void	send_back(t_carrier *pigeons);
/* end */

#endif
