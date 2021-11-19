/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:31 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/19 07:11:00 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *x, t_stack *y);

void	push_stack(t_push_swap *root)
{
	if (root->ctrl == pa)
		push(root->b, root->a);
	else
		push(root->a, root->b);
	write(1, root->operation_strs[root->ctrl], 3);
}

static void	push(t_stack *x, t_stack *y)
{
	ft_memmove(y->stack + 1, y->stack, y->nums++ * sizeof(int));
	y->stack[0] = x->stack[0];
	ft_memmove(x->stack, x->stack + 1, --x->nums * sizeof(int));
}
