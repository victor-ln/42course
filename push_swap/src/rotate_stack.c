/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:19:28 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/19 07:10:42 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *x);
static void	reverse_rotate(t_stack *x);

void	rotate_stack(t_push_swap *root)
{
	if (root->ctrl == ra)
		rotate(root->a);
	else if (root->ctrl == rb)
		rotate(root->b);
	else
	{
		rotate(root->a);
		rotate(root->b);
	}
	write(1, root->operation_strs[root->ctrl], 3);
}

void	reverse_rotate_stack(t_push_swap *root)
{
	if (root->ctrl == rra)
		reverse_rotate(root->a);
	else if (root->ctrl == rrb)
		reverse_rotate(root->b);
	else
	{
		reverse_rotate(root->a);
		reverse_rotate(root->b);
	}
	write(1, root->operation_strs[root->ctrl], 4);
}

static void	rotate(t_stack *x)
{
	int		temp;

	temp = x->stack[0];
	ft_memmove(x->stack, x->stack + 1, (x->nums - 1) * sizeof(int));
	x->stack[x->nums - 1] = temp;
}

static void	reverse_rotate(t_stack *x)
{
	int		temp;

	temp = x->stack[x->nums - 1];
	ft_memmove(x->stack + 1, x->stack, (x->nums - 1) * sizeof(int));
	x->stack[0] = temp;
}
