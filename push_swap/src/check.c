/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:34:11 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 16:38:52 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *x)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	while (++i < x->n)
	{
		j = 0;
		num = x->st[i];
		while (j < i)
			if ((x->st[j++] > num) != x->order)
				return (0);
		while (++j < x->n)
			if ((x->st[j] < num) != x->order)
				return (0);
	}
	return (1);
}

int	repeats(t_stack *stack)
{
	size_t	i;
	size_t	j;
	int		num;

	i = 0;
	while (i < stack->n)
	{
		j = i;
		num = stack->st[i++];
		while (++j < stack->n)
			if (num == stack->st[j])
				return (1);
	}
	return (0);
}

int	check_range(t_stack *a)
{
	size_t	i;
	int		min;
	int		max;

	i = 0;
	min = *a->st;
	max = *a->st;
	while (++i < a->n)
	{
		if (min > a->st[i])
			min = a->st[i];
		if (max < a->st[i])
			max = a->st[i];
	}
	return ((size_t)(max - min) <= a->n * 10);
}
