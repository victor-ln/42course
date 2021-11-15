/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 00:13:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/15 17:28:20 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_push_swap *root);

int	main(int argc, char **argv)
{
	t_push_swap		*root;

	root = (t_push_swap *)ft_calloc(sizeof(t_push_swap), 1);
	if (!root || argc != 2)
		end_program(root, 1);
	start_stack(argv[1], root);
	sort_stack(root);
}

static void	sort_stack(t_push_swap *root)
{
	while (check_stack(root))
	{
		root->operation[root->ctrl](root);
	}
	end_program(root, 0);
}
