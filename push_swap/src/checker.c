/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 18:37:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 22:25:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	finish_program(t_push_swap *data, int status);
static void	read_instructions(t_push_swap *data);
static int	execute_instruction(t_push_swap *data, char *command);

int	main(int argc, char **argv)
{
	t_push_swap		*data;

	data = (t_push_swap *)ft_calloc(sizeof(t_push_swap), 1);
	if (!data)
		end_program(data, 1);
	init_program(argv, argc, data);
	read_instructions(data);
}

static void	read_instructions(t_push_swap *data)
{
	int		i;
	char	command[5];

	i = 0;
	while (read(0, &command[i], 1) > 0)
	{
		if (!ft_strchr("rapbs\n", command[i]) || i == 4)
			finish_program(data, 2);
		else if (command[i] == '\n')
		{
			command[i + 1] = 0;
			i = 0;
			if (execute_instruction(data, command))
				continue ;
			finish_program(data, 2);
		}
		i++;
	}
	finish_program(data, (is_sorted(data->a) && !data->b->n));
}

static int	execute_instruction(t_push_swap *data, char *command)
{
	if (!ft_strcmp("sa\n", command))
		swap(data, A);
	else if (!ft_strcmp("sb\n", command))
		swap(data, B);
	else if (!ft_strcmp("ss\n", command))
		swap(data, R);
	else if (!ft_strcmp("ra\n", command))
		rotate(data, A);
	else if (!ft_strcmp("rb\n", command))
		rotate(data, B);
	else if (!ft_strcmp("rr\n", command))
		rotate(data, R);
	else if (!ft_strcmp("rra\n", command))
		reverse_rotate(data, A);
	else if (!ft_strcmp("rrb\n", command))
		reverse_rotate(data, B);
	else if (!ft_strcmp("rrr\n", command))
		reverse_rotate(data, R);
	else if (!ft_strcmp("pa\n", command))
		push(data, A);
	else if (!ft_strcmp("pb\n", command))
		push(data, B);
	else
		return (0);
	return (1);
}

static void	finish_program(t_push_swap *data, int status)
{
	if (!status)
		ft_putstr_fd("KO\n", 1);
	else if (status == 1)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("Error\n", 2);
	end_program(data, 0);
}
