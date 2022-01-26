/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:31 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 17:30:28 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_stack *x, t_stack *y);

void	push(t_push_swap *data, int operation)
{
	if (operation == A)
		push_stack(data->b, data->a);
	else
		push_stack(data->a, data->b);
	if (!BONUS)
		write(1, data->operation_strs[3][operation], 3);
}

static void	push_stack(t_stack *x, t_stack *y)
{
	if (!x->n)
		return ;
	ft_memmove(y->st + 1, y->st, y->n++ * sizeof(int));
	y->st[0] = x->st[0];
	ft_memmove(x->st, x->st + 1, --x->n * sizeof(int));
}
