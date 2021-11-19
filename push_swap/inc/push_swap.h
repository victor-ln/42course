/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:13:53 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/19 07:09:16 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

enum e_actions{
	sa,
	sb,
	ss,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	pa,
	pb
};

typedef struct s_push_swap	t_push_swap;
typedef struct s_stack		t_stack;

struct s_stack
{
	int			*stack;
	size_t		nums;
};

struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	int			ctrl;
	void		(*operation[11])(t_push_swap *);
	char		*operation_strs[11];
};

/*
	Writes Error\\n if status is equals to EXIT_FAILURE,
	frees all allocated memory and exits with the status given.
*/
void		end_program(t_push_swap *root, int status);

/*
	Compares each number of stack with all their
	successors. Returns 1 if a number repeats, else
	sets some variables in the stack and returns 0.
*/
int			repeats(t_stack *stack);

/*
	Compares each number of stack with all their n
	successors. Order can be 1 or 0. 1 means ascending, zero the opposite.
	Returns 1 if its not sorted in the order given, else returns 0.
*/
int			not_sorted(int *stack, int order, size_t n);

/*
	Gets how many numbers there are to put in the stack a,
	allocates this amount, converts argv to integers, stores them in the
	stack a, checks for duplicate numbers and finally
	copies the name of all operations used to sort the
	stack to write them when they are used.
*/
void		start_stack(char *ptr, t_push_swap *root);

/*
	Swaps the first 2 elements at the top of the stack a,
	b or both at the same time.
	Writes which operation was executed.
*/
void		swap_stack(t_push_swap *root);

/*
	Takes the first element on top of b and puts
	it on top of a, and the reverse.
	Writes which operation was executed.
*/
void		push_stack(t_push_swap *root);

/*
	Shifts up all elements of stack a, b or both at the same time.
	Writes which operation was executed.
*/
void		rotate_stack(t_push_swap *root);

/*
	Shifts down all elements of stack a, b or both at the same time.
	Writes which operation was executed.
*/
void		reverse_rotate_stack(t_push_swap *root);

#endif
