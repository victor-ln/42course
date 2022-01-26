/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:39:49 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 18:39:53 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap		*data;

	data = (t_push_swap *)ft_calloc(sizeof(t_push_swap), 1);
	if (!data)
		end_program(data, 1);
	init_program(argv, argc, data);
	end_program(data, 0);
}
