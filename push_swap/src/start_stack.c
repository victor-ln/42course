/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:35:00 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 17:01:21 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_len(char *ptr, t_push_swap *root);
static void	set_operations(t_push_swap *root);

void	start_stack(char *ptr, t_push_swap *root)
{
	int		i;

	i = 0;
	stack_len(ptr, root);
	while (*ptr)
	{
		while (ft_isdigit(*ptr))
			root->a->stack[i] = (root->a->stack[i] * 10) + (*ptr++ - '0');
		if (!*ptr)
			break ;
		if (*ptr != ' ')
			end_program(root, 1);
		ptr++;
		i++;
	}
	root->operator = is_equal;
	if (check_stack(root))
		end_program(root, 1);
	root->operator = is_bigger;
	set_operations(root);
}

static void	stack_len(char *ptr, t_push_swap *root)
{
	while (*ptr)
	{
		if (ft_isdigit(*ptr) && (*(ptr + 1) == ' ' || !*(ptr + 1)))
			root->numbers++;
		ptr++;
	}
	if (root->numbers < 2)
		end_program(root, 0);
	root->a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	root->b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!root->a || !root->b)
		end_program(root, 1);
	root->a->stack = (int *)ft_calloc(sizeof(int), root->numbers);
	root->b->stack = (int *)ft_calloc(sizeof(int), root->numbers);
	if (!root->a || !root->b)
		end_program(root, 1);
	root->a->numbers = root->numbers;
}

static void	set_operations(t_push_swap *root)
{
	root->operation_strs[sa] = "sa\n";
	root->operation_strs[sb] = "sb\n";
	root->operation_strs[ss] = "ss\n";
	root->operation_strs[ra] = "ra\n";
	root->operation_strs[rb] = "rb\n";
	root->operation_strs[rr] = "rr\n";
	root->operation_strs[pa] = "pa\n";
	root->operation_strs[pb] = "pb\n";
	root->operation_strs[rra] = "rra\n";
	root->operation_strs[rrb] = "rrb\n";
	root->operation_strs[rrr] = "rrr\n";
	root->operation[sa] = swap_stack;
	root->operation[sb] = swap_stack;
	root->operation[ss] = swap_stack;
	root->operation[pa] = push_stack;
	root->operation[pb] = push_stack;
	root->operation[ra] = rotate_stack;
	root->operation[rb] = rotate_stack;
	root->operation[rr] = rotate_stack;
	root->operation[rra] = reverse_rotate_stack;
	root->operation[rrb] = reverse_rotate_stack;
	root->operation[rrr] = reverse_rotate_stack;
}
