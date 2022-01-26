/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:46 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 17:31:54 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_stack *x);

void	swap(t_push_swap *data, int operation)
{
	if (operation == A || operation == R)
		swap_stack(data->a);
	if (operation == B || operation == R)
		swap_stack(data->b);
	if (!BONUS)
		write(1, data->operation_strs[0][operation], 3);
}

static void	swap_stack(t_stack *x)
{
	int		temp;

	if (x->n < 2)
		return ;
	temp = x->st[1];
	x->st[1] = x->st[0];
	x->st[0] = temp;
}
