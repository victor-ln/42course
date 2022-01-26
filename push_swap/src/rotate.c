/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:19:28 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 17:32:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_stack *x);
static void	reverse_rotate_stack(t_stack *x);

void	rotate(t_push_swap *data, int operation)
{
	if (operation == A || operation == R)
		rotate_stack(data->a);
	if (operation == B || operation == R)
		rotate_stack(data->b);
	if (!BONUS)
		write(1, data->operation_strs[1][operation], 3);
}

void	reverse_rotate(t_push_swap *data, int operation)
{
	if (operation == A || operation == R)
		reverse_rotate_stack(data->a);
	if (operation == B || operation == R)
		reverse_rotate_stack(data->b);
	if (!BONUS)
		write(1, data->operation_strs[2][operation], 4);
}

static void	rotate_stack(t_stack *x)
{
	int		temp;

	if (x->n < 2)
		return ;
	temp = *x->st;
	ft_memmove(x->st, x->st + 1, (x->n - 1) * sizeof(int));
	x->st[x->n - 1] = temp;
}

static void	reverse_rotate_stack(t_stack *x)
{
	int		temp;

	if (x->n < 2)
		return ;
	temp = x->st[x->n - 1];
	ft_memmove(x->st + 1, x->st, (x->n - 1) * sizeof(int));
	*x->st = temp;
}
