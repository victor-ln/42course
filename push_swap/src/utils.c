/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:32:23 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 22:12:59 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	compare(t_stack *x);

void	sort_five(t_push_swap *d)
{
	while (!is_sorted(d->a) || d->b->n)
	{
		if (d->a->st[0] > d->a->st[d->a->n - 1])
			rotate(d, A + \
					(*d->b->st < d->b->st[d->b->n - 1] && d->b->n > 1) * 2);
		else if (d->a->st[0] > d->a->st[1])
			swap(d, A + (d->b->st[0] < d->b->st[1] && d->b->n > 1) * 2);
		else if (!is_sorted(d->a))
			push(d, B);
		else if (d->a->n + d->b->n <= 5)
			push(d, A);
		else
			break ;
	}
}

void	split_stack(t_push_swap *data)
{
	float	a;
	float	b;

	a = 1.5;
	b = 5;
	if (data->a->n < 50)
	{
		a = 3;
		b = 2;
	}
	while (data->a->n > 5)
	{
		if (!(compare(data->a) > data->a->n / a))
			rotate(data, A + (compare(data->b) > data->b->n / b) * 2);
		else
		{
			if (compare(data->b) > data->b->n / b)
				rotate(data, B);
			push(data, B);
		}
	}
	sort_five(data);
}

int	count_operations(int *pos)
{
	if (pos[A] * pos[B] > 0)
	{
		if (pos[A] > 0)
		{
			if (pos[A] > pos[B])
				return (pos[A]);
			return (pos[B]);
		}
		else if (pos[A] < pos[B])
			return (-pos[A]);
		else
			return (-pos[B]);
	}
	else
		return (ft_abs(pos[A]) + ft_abs(pos[B]));
}

static size_t	compare(t_stack *x)
{
	size_t	n;
	size_t	i;

	n = 0;
	i = 0;
	while (++i < x->n)
		if (x->st[0] < x->st[i])
			n++;
	return (n);
}

size_t	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}
