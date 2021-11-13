/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:13:53 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/13 13:37:57 by vlima-nu         ###   ########.fr       */
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

typedef struct s_stack
{
	int			*a;
	int			*b;
	size_t		a_numbers;
	size_t		b_numbers;
	size_t		numbers;
	int			action;
	char		*actions_strs[11];
	int			(*operator)(int, int);
}	t_stack;

/*
	Writes Error\\n if status is equals to EXIT_FAILURE,
	frees all allocated memory and exits with the status given.
*/
void		end_program(t_stack *stacks, int status);

/*
	Compares each number of stack a with all their
	successors using the function pointer operator,
	that can be the is_equal or is_bigger functions.
*/
int			check_stack(t_stack *stack);

/*
	Gets how many numbers there are to put in the stack a,
	allocates this amount, converts argv to integers, stores them in the
	stack a, checks for duplicate numbers and finally
	copies the name of all actions used to sort the
	stack to write them when they are used.
*/
void		start_stack(char *ptr, t_stack *stack);

void		sort_stack(t_stack *stacks);

int			is_bigger(int num, int stack_num);
int			is_equal(int num, int stack_num);

#endif
