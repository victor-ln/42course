/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:13:53 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 21:17:13 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"

# define A		0
# define B		1
# define R		2

enum e_order{
	ascending,
	descending
};

typedef struct s_push_swap	t_push_swap;
typedef struct s_stack		t_stack;

struct s_stack
{
	int			*st;
	size_t		order;
	size_t		n;
};

struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			*pos;
	int			*tmp;
	int			counter;
	int			op;
	void		(*ft[2])(t_push_swap *, int);
	int			parity_bit;
	char		*operation_strs[4][3];
};

/*
	Writes Error\\n if status is equals to EXIT_FAILURE,
	frees all allocated memory and exits with the status given.
*/
void		end_program(t_push_swap *data, int status);

/*
	Compares each number of stack with all their
	successors. Returns 1 if a number repeats, else
	sets some variables in the stack and returns 0.
*/
int			repeats(t_stack *stack_a);

/*
	Compares each number of stack with all their n
	successors. Order can be 1 or 0. 1 means ascending, zero the opposite.
	Returns 1 if its not sorted in the order given, else returns 0.
*/
int			is_sorted(t_stack *stack_x);

/*
	Gets how many numbers there are to put in the stack a,
	allocates this amount, converts argv to integers, stores them in the
	stack a, checks for duplicate numbers and finally
	copies the name of all operations used to sort the
	stack to write them when they are used.
*/
void		init_program(char **nptr, int argc, t_push_swap *data);

/*
	Swaps the first 2 elements at the top of the stack a,
	b or both at the same time.
	Writes which operation was executed.
*/
void		swap(t_push_swap *data, int operation);

/*
	Takes the first element on top of b and puts
	it on top of a, and the reverse.
	Writes which operation was executed.
*/
void		push(t_push_swap *data, int operation);

/*
	Shifts up all elements of stack a, b or both at the same time.
	Writes which operation was executed.
*/
void		rotate(t_push_swap *data, int operation);

/*
	Shifts down all elements of stack a, b or both at the same time.
	Writes which operation was executed.
*/
void		reverse_rotate(t_push_swap *data, int operation);

void		radix_sort(t_push_swap *data);

void		sort_stack(t_push_swap *data);

void		split_stack(t_push_swap *data);

void		sort_five(t_push_swap *data);

int			count_operations(int *pos);

size_t		ft_abs(int num);

int			check_range(t_stack *a);

#endif
