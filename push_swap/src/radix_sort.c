/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:32:21 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 16:38:46 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	selected_pushing(t_push_swap *data);
static void	finish(t_push_swap *data);
static int	check_parity(t_stack *x, int bit);

void	radix_sort(t_push_swap *data)
{
	size_t	i;
	size_t	n;

	data->parity_bit = 1;
	while (data->parity_bit != INT_MIN)
	{
		i = 0;
		n = data->a->n;
		if (check_parity(data->a, data->parity_bit))
		{
			while (++i <= n)
			{
				if (is_sorted(data->a) && is_sorted(data->b))
					finish(data);
				if (*data->a->st & data->parity_bit)
					rotate(data, A);
				else
					push(data, B);
			}
		}
		selected_pushing(data);
	}
}

static void	selected_pushing(t_push_swap *data)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = data->b->n;
	data->parity_bit <<= 1;
	if (check_parity(data->b, data->parity_bit))
	{
		while (++i <= n)
		{
			if (is_sorted(data->a) && is_sorted(data->b))
				finish(data);
			if (*data->b->st & data->parity_bit)
				push(data, A);
			else
				rotate(data, B);
		}
	}
}

static void	finish(t_push_swap *data)
{
	size_t	op;

	op = data->b->n > data->a->n;
	while (data->b->n)
		push(data, A);
	if (!is_sorted(data->a))
		while (*data->a->st > data->a->st[data->a->n - 1])
			data->ft[op](data, A);
	end_program(data, 0);
}

static int	check_parity(t_stack *x, int bit)
{
	size_t	i;

	i = 0;
	while (i < x->n)
		if (x->st[i++] & bit)
			return (1);
	return (0);
}
