/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/07/24 17:04:25 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define ASC 0
# define DESC 1

# define NORTH 0
# define SOUTH 1

# define STACK_A 0
# define STACK_B 1

/*
structure for nodes to contain a int
an a link to the next node
*/
typedef struct stack
{
	int				value;
	int				index;
	int				family;
	struct stack	*next;
}	t_stack;

/* keeps track of both stacks and other stuffs */
typedef struct carrier
{
	int				min_a;
	int				max_a;
	int				min_b;
	int				max_b;
	bool			c_snd;
	char			**argv;
	int				size_a;
	int				size_b;
	int				siblings;
	int				families;
	struct stack	*head_a;
	struct stack	*tail_a;
	struct stack	*head_b;
	struct stack	*tail_b;
}	t_carrier;

/* main */
int		main(int argc, char **argv);

/* validate and clean the inputs */
bool	validate_input(int save, char *str);
bool	int_within_range(int num, char *str);
bool	no_random_chars(char *str);
int		duplicate_inputs(t_carrier *pigeons);
int		special_parcing(t_carrier *pigeons, char **argv, int *argc);
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
int		is_stack_sorted(t_stack *head);
t_stack	*push(int num, int fam, t_stack *head);
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
void	sort_ten(t_carrier *pigeons);
void	sort_five(t_carrier *pigeons);
void	sort_three(t_carrier *pigeons, int size);

void	rollback(t_carrier *pigeons, t_stack *stack, int stk);
void	find_siblings(t_carrier *pigeons);

/* helpers */
int		find_position(t_stack *stack, int to_find);
int		*map_and_sort(t_stack *head, int size);
int		find_moves(t_carrier *pigeons, int val, int *direction, int stk);

/* sorting */

/* stage one */
void	send_to_b(t_carrier *pigeons, int first, int second);
void	go(t_carrier *pigeons, int moves, int dir, bool is_rr);
t_stack	*node_to_send(t_carrier *pigeons, int first, int second, int *dir);
void	send_last_two(t_carrier *pigeons, int first, int second, int *dir);

/* stage two */
void	send_back(t_carrier *pigeons);
void	manage_last_snd(t_carrier *pigeons);
int		find_place_instack(t_carrier *pigeons,
			bool c_snd, bool l_snd, bool get);

/* end */

#endif
