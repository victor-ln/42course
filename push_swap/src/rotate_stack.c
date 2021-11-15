/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:19:28 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 17:01:21 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *x);
static void	reverse_rotate(t_stack *x);

void	rotate_stack(t_push_swap *root)
{
	if (root->operation == ra || root->operation == rr)
		rotate(root->a);
	if (root->operation == rb || root->operation == rr)
		rotate(root->b);
	write(1, root->operation_strs[root->ctrl], 3);
}

void	reverse_rotate_stack(t_push_swap *root)
{
	if (root->operation == rra || root->operation == rrr)
		reverse_rotate(root->a);
	if (root->operation == rrb || root->operation == rrr)
		reverse_rotate(root->b);
	write(1, root->operation_strs[root->ctrl], 4);
}

static void	rotate(t_stack *x)
{
	int		temp;

	temp = *x->stack;
	ft_memcpy(x->stack, x->stack + 1, (x->numbers - 1) * sizeof(int));
	*(x->stack + (x->numbers - 1)) = temp;
}

static void	reverse_rotate(t_stack *x)
{
	int		temp;

	temp = *(x->stack + (x->numbers - 1));
	ft_memmove(x->stack + 1, x->stack, (x->numbers - 1) * sizeof(int));
	*x->stack = temp;
}
