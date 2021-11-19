/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:46 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/18 00:05:33 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack *y);

void	swap_stack(t_push_swap *root)
{
	if (root->ctrl == sa)
		swap(root->a);
	else if (root->ctrl == sb)
		swap(root->b);
	else
	{
		swap(root->a);
		swap(root->b);
	}
	write(1, root->operation_strs[root->ctrl], 3);
}

static void	swap(t_stack *x)
{
	x->stack[0] ^= x->stack[1];
	x->stack[1] ^= x->stack[0];
	x->stack[0] ^= x->stack[1];
}
