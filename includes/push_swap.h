/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:05:50 by rphuyal           #+#    #+#             */
/*   Updated: 2023/06/19 02:15:16 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# define GREEN 			"\033[0;32m"
# define RED 			"\033[0;31m"
# define YELLOW 		"\x1b[33m"
# define CYAN 			"\x1b[36m"
# define PURPLE 		"\x1b[35m"
# define SALMON			"\033[38;5;209m"
# define SBLUE			"\033[38;5;117m"
# define RESET 			"\033[0m"

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
	int				size_a;
	int				min_even;
	int				max_even;
	int				min_odd;
	int				max_odd;
	struct stack	*head_a;
	struct stack	*tail_a;
	struct stack	*head_b;
	struct stack	*tail_b;
}	t_carrier;

typedef struct array_stack
{
	int a_end;
	int a_start;
	int	*stack_head;
}	t_array_stack;

/* keeps track of a lot of stuffs */
typedef struct stack_carrier
{
	int					min_odd;
	int					max_odd;
	int					min_even;
	int					max_even;
	struct array_stack	*stack_a;
	struct array_stack	*stack_b;
}	t_stack_carrier;

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

/* utils */
void	ft_print_list(t_carrier *pigeons);
void	print_stack(t_stack *head);
int		find_index(char **argv);
/* end */

/* stack */
/* basic stack operations */
int		stack_size(t_stack *lst);
int		is_stack_sorted(t_carrier *pigeons);
t_stack	*push(int num, t_stack *head);
t_stack	*pop(t_stack *head);

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
void	reset_all_limits(t_carrier *pigeons);
void	find_min_max(t_carrier *pigeons, t_stack *stack, int index);
/* end */

#endif
