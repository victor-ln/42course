/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 16:15:46 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 17:20:37 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(int *x, int *y);

void	swap_stack(t_push_swap *root)
{
	if (root->ctrl == sa || root->ctrl == ss)
		swap(root->a->stack, root->a->stack + 1);
	if (root->ctrl == sb || root->ctrl == ss)
		swap(root->b->stack, root->b->stack + 1);
	write(1, root->operation_strs[root->ctrl], 3);
}

static void	swap(int *x, int *y)
{
	*x ^= *y;
	*y ^= *x;
	*x ^= *y;
}
