/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:09:52 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/13 12:29:29 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	if (stack->numbers != stack->a_numbers)
		return (1);
	while (i < stack->a_numbers)
	{
		j = i;
		num = stack->a[i];
		while (++j < stack->a_numbers)
			if (stack->operator(num, stack->a[j]))
				return (1);
		i++;
	}
	return (0);
}

int	is_equal(int num, int stack_num)
{
	return (num == stack_num);
}

int	is_bigger(int num, int stack_num)
{
	return (num > stack_num);
}
