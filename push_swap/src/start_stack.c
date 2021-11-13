/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:35:00 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/13 13:01:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_len(char *ptr, t_stack *stack);
static void	actions_strs(char **actions);

void	start_stack(char *ptr, t_stack *stack)
{
	int		i;

	i = 0;
	stack_len(ptr, stack);
	while (*ptr)
	{
		while (ft_isdigit(*ptr))
			stack->a[i] = (stack->a[i] * 10) + (*ptr++ - '0');
		if (!*ptr)
			break ;
		if (*ptr != ' ')
			end_program(stack, 1);
		ptr++;
		i++;
	}
	stack->operator = is_equal;
	if (check_stack(stack))
		end_program(stack, 1);
	stack->operator = is_bigger;
	actions_strs(stack->actions_strs);
}

static void	stack_len(char *ptr, t_stack *stack)
{
	while (*ptr)
	{
		if (ft_isdigit(*ptr) && (*(ptr + 1) == ' ' || !*(ptr + 1)))
			stack->numbers++;
		ptr++;
	}
	if (stack->numbers < 2)
		end_program(stack, 0);
	stack->a = ft_calloc(sizeof(int), stack->numbers);
	stack->b = ft_calloc(sizeof(int), stack->numbers);
	if (!stack->a || !stack->b)
		end_program(stack, 1);
	stack->a_numbers = stack->numbers;
}

static void	actions_strs(char **actions)
{
	actions[sa] = "sa\n";
	actions[sb] = "sb\n";
	actions[ss] = "ss\n";
	actions[ra] = "ra\n";
	actions[rb] = "rb\n";
	actions[rr] = "rr\n";
	actions[rra] = "rra\n";
	actions[rrb] = "rrb\n";
	actions[rrr] = "rrr\n";
	actions[pa] = "pa\n";
	actions[pb] = "pb\n";
}
