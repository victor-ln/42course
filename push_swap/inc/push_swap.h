/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:13:53 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 17:22:17 by vlima-nu         ###   ########.fr       */
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
	int		*stack;
	size_t	numbers;
};

struct s_push_swap
{
	t_stack		*a;
	t_stack		*b;
	size_t		numbers;
	int			ctrl;
	char		*operation_strs[11];
	void		(*operation[11])(t_push_swap *);
	int			(*operator)(int, int);
};

/*
	Writes Error\\n if status is equals to EXIT_FAILURE,
	frees all allocated memory and exits with the status given.
*/
void		end_program(t_push_swap *root, int status);

/*
	Compares each number of stack a with all their
	successors using the function pointer operator,
	that can be the is_equal or is_bigger functions.
*/
int			check_stack(t_push_swap *root);

/*
	Gets how many numbers there are to put in the stack a,
	allocates this amount, converts argv to integers, stores them in the
	stack a, checks for duplicate numbers and finally
	copies the name of all operations used to sort the
	stack to write them when they are used.
*/
void		start_stack(char *ptr, t_push_swap *root);

int			is_bigger(int num, int stack_num);
int			is_equal(int num, int stack_num);

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
