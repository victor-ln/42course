/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:13:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/13 11:37:32 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack;

	stack = ft_calloc(sizeof(t_stack), 1);
	if (!stack || argc != 2)
		end_program(stack, 1);
	start_stack(argv[1], stack);
	sort_stack(stack);
}

void	sort_stack(t_stack *stack)
{
	while (check_stack(stack))
	{
		ft_putstr_fd(stack->actions_strs[stack->action], 1);
	}
	end_program(stack, 0);
}
