/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:31 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 17:14:03 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *x, t_stack *y);

void	push_stack(t_push_swap *root)
{
	if (root->ctrl == pa && root->a->numbers)
		push(root->a, root->b);
	else if (root->b->numbers)
		push(root->b, root->a);
	write(1, root->operation_strs[root->ctrl], 3);
}

static void	push(t_stack *x, t_stack *y)
{
	ft_memmove(y->stack + 1, y->stack, y->numbers++ * sizeof(int));
	*y->stack = *x->stack;
	ft_memcpy(x->stack, x->stack + 1, --x->numbers * sizeof(int));
}
