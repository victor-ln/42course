/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 02:44:50 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 15:51:41 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	end_program(t_push_swap *root, int status)
{
	if (status)
		ft_putstr_fd("Error\n", 2);
	if (root)
	{
		if (root->a)
		{
			if (root->a->stack)
				free(root->a->stack);
			free(root->a);
		}
		if (root->b)
		{
			if (root->b->stack)
				free(root->b->stack);
			free(root->b);
		}
		free(root);
	}
	exit(status);
}
