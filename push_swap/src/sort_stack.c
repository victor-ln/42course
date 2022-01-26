/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:30:38 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 22:10:40 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_pos(t_push_swap *data, int b);
static void	push_back(t_push_swap *data);
static void	insert(t_push_swap *data);
static void	align(t_push_swap *data);

void	sort_stack(t_push_swap *data)
{
	if (data->a->n >= 5000 && check_range(data->a))
		radix_sort(data);
	else
	{
		split_stack(data);
		push_back(data);
		align(data);
	}
}

static void	align(t_push_swap *data)
{
	size_t	op;
	size_t	i;
	size_t	n;

	if (is_sorted(data->a))
		return ;
	i = 0;
	n = 0;
	while (++i < data->a->n)
		if (data->a->st[i] > data->a->st[n])
			n = i;
	op = ++n > data->a->n / 2;
	if (n > data->a->n - n)
		n = data->a->n - n;
	while (n)
	{
		data->ft[op](data, A);
		n--;
	}
}

static void	insert(t_push_swap *data)
{
	data->op = data->pos[A] < 0;
	if (data->pos[A] * data->pos[B] > 0)
	{
		if (data->pos[A] > 0)
			data->counter = data->pos[data->pos[A] > data->pos[B]];
		else
			data->counter = data->pos[data->pos[A] < data->pos[B]];
		data->pos[A] -= data->counter;
		data->pos[B] -= data->counter;
		data->counter = ft_abs(data->counter);
		while (--data->counter >= 0)
			data->ft[data->op](data, R);
	}
	data->pos[A] = ft_abs(data->pos[A]);
	while (--data->pos[A] >= 0)
		data->ft[data->op](data, A);
	data->op = data->pos[B] < 0;
	data->pos[B] = ft_abs(data->pos[B]);
	while (--data->pos[B] >= 0)
		data->ft[data->op](data, B);
	push(data, A);
}

static void	push_back(t_push_swap *data)
{
	size_t	i;

	data->pos = (int *)malloc(sizeof(int) * 2);
	data->tmp = (int *)malloc(sizeof(int) * 2);
	if (!data->pos || !data->tmp)
		end_program(data, 1);
	while (data->b->n)
	{
		i = 0;
		data->pos[A] = find_pos(data, data->b->st[i]);
		data->pos[B] = i++;
		while (i < data->b->n / 2 && (int)i < count_operations(data->pos))
		{
			data->tmp[A] = find_pos(data, data->b->st[i]);
			data->tmp[B] = i;
			if (count_operations(data->pos) > count_operations(data->tmp))
				ft_memcpy(data->pos, data->tmp, sizeof(int) * 2);
			data->tmp[A] = find_pos(data, data->b->st[data->b->n - i]);
			data->tmp[B] = -i;
			if (count_operations(data->pos) > count_operations(data->tmp))
				ft_memcpy(data->pos, data->tmp, sizeof(int) * 2);
			i++;
		}
		insert(data);
	}
}

static int	find_pos(t_push_swap *data, int num)
{
	size_t	i;
	size_t	max;

	i = 0;
	if (num < data->a->st[0] && \
		num > data->a->st[data->a->n - 1])
		return (0);
	while (++i < data->a->n)
		if (num < data->a->st[i] && num > data->a->st[i - 1])
			return (((i <= data->a->n - i) * i) + \
					((i > data->a->n - i) * -(data->a->n - i)));
	i = 0;
	max = i;
	while (++i < data->a->n)
		if (data->a->st[i] > data->a->st[max])
			max = i;
	if (++max > data->a->n / 2)
		return (-(data->a->n - max));
	return (max);
}
