/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:09:52 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/19 07:03:42 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	not_sorted(int *stack, int order, size_t n)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	while (++i < n)
	{
		j = 0;
		num = stack[i];
		while (j < i)
			if ((stack[j++] > num) == order)
				return (1);
		while (++j < n)
			if ((stack[j] < num) == order)
				return (1);
	}
	return (0);
}

int	repeats(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	while (i < stack->nums)
	{
		j = i;
		num = stack->stack[i++];
		while (++j < stack->nums)
			if (num == stack->stack[j])
				return (1);
	}
	return (0);
}
