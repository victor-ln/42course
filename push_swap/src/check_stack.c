/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 03:09:52 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 15:52:23 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack(t_push_swap *root)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	if (root->numbers != root->a->numbers)
		return (1);
	while (i < root->a->numbers)
	{
		j = i;
		num = root->a->stack[i];
		while (++j < root->a->numbers)
			if (root->operator(num, root->a->stack[j]))
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
