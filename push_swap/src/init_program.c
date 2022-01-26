/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 22:11:26 by vlima-nu          #+#    #+#             */
/*   Updated: 2022/01/25 19:13:48 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	save_numbers(char **nptr, int argc, t_push_swap *data);
static void	init_stack(char **nptr, int argc, t_push_swap *data);
static void	def_operations(t_push_swap *data);
static char	*convert(char *nptr, int *vector);

void	init_program(char **nptr, int argc, t_push_swap *data)
{
	data->a = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	data->b = (t_stack *)ft_calloc(sizeof(t_stack), 1);
	if (!data->a || !data->b)
		end_program(data, 1);
	init_stack(nptr, argc, data);
	save_numbers(nptr, argc, data);
	if (data->a->n < 2 && !BONUS)
		end_program(data, 0);
	if (repeats(data->a))
		end_program(data, 1);
	def_operations(data);
	data->b->order = descending;
	if (!is_sorted(data->a) && !BONUS)
		sort_stack(data);
}

static void	init_stack(char **nptr, int argc, t_push_swap *data)
{
	int		j;
	size_t	i;

	j = 0;
	while (++j < argc)
	{
		if (!ft_strlen(nptr[j]))
			end_program(data, 1);
		i = 0;
		while (nptr[j][i])
		{
			if (!ft_strchr("-+ ", nptr[j][i]) && !ft_isdigit(nptr[j][i]))
				end_program(data, 1);
			else if (ft_strchr("-+", nptr[j][i]) && !ft_isdigit(nptr[j][i + 1]))
				end_program(data, 1);
			else if (ft_isdigit(nptr[j][i]) && !ft_isdigit(nptr[j][i + 1]))
				data->a->n++;
			i++;
		}
	}
	data->a->st = (int *)malloc(sizeof(int) * data->a->n);
	data->b->st = (int *)malloc(sizeof(int) * data->a->n);
	if (!data->a->st || !data->b->st)
		end_program(data, 1);
}

static void	save_numbers(char **nptr, int argc, t_push_swap *data)
{
	size_t	i;
	int		j;

	j = 0;
	i = 0;
	while (++j < argc)
	{
		while (*nptr[j])
		{
			while (*nptr[j] == ' ')
				nptr[j]++;
			nptr[j] = convert(nptr[j], data->a->st + i++);
			if (!nptr[j])
				end_program(data, 1);
		}
	}
}

static char	*convert(char *nptr, int *vector)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	while (ft_isdigit(*nptr) && num <= 2147483648)
		num = num * 10 + *nptr++ - '0';
	num *= sign;
	if (num > INT_MAX || num < INT_MIN)
		return (NULL);
	*vector = (int)(num);
	return (nptr);
}

static void	def_operations(t_push_swap *data)
{
	data->operation_strs[0][A] = "sa\n";
	data->operation_strs[0][B] = "sb\n";
	data->operation_strs[0][R] = "ss\n";
	data->operation_strs[1][A] = "ra\n";
	data->operation_strs[1][B] = "rb\n";
	data->operation_strs[1][R] = "rr\n";
	data->operation_strs[2][A] = "rra\n";
	data->operation_strs[2][B] = "rrb\n";
	data->operation_strs[2][R] = "rrr\n";
	data->operation_strs[3][A] = "pa\n";
	data->operation_strs[3][B] = "pb\n";
	data->ft[0] = rotate;
	data->ft[1] = reverse_rotate;
}
