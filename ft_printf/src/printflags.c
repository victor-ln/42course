/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:00:06 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:00:06 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	zero_flag(t_params p, int len);

int	ft_print_hash_flag(t_params p, char *arg)
{
	if (((ft_strchr("xX", p.specifier) && p.hash) || (p.specifier == 'p'))
		&& (p.zero_or_blank == '0' && !p.precision_char))
		return (0);
	if (p.specifier == 'p')
		return (write(1, "0x", 2));
	else if (!ft_strcmp(arg, "0"))
		return (0);
	else if (p.specifier == 'x' && p.hash)
		return (write(1, "0x", 2));
	else if (p.specifier == 'X' && p.hash)
		return (write(1, "0X", 2));
	return (0);
}

int	ft_print_zeros_or_blank_flag(t_params p, int len, char **arg)
{
	if ((!p.zero_or_blank && p.width > len)
		|| (p.specifier == 's' && p.zero_or_blank == '0'))
		return (ft_printchar(p.width, ' ', len));
	if (p.zero_or_blank == '0' && p.width > len)
	{
		if (*arg[0] == '-' && ft_strchr("di", p.specifier))
		{
			if (p.precision_char)
				return ((zero_flag(p, (len + 1))));
			return ((write(1, "-", 1)) + (zero_flag(p, len)));
		}
		if (p.plus_or_space && ft_strchr("di", p.specifier)
			&& !p.precision_char)
		{
			if (p.plus_or_space == ' ')
				write(1, " ", 1);
			else
				write(1, "+", 1);
			return (zero_flag(p, len) + 1);
		}
		return (zero_flag(p, len));
	}
	return (0);
}

static int	zero_flag(t_params p, int len)
{
	if (p.precision <= len && p.precision >= 0 && p.precision_char)
		return (ft_printchar(p.width, ' ', len));
	if (p.precision >= p.width && p.precision_char)
		return (ft_printchar(p.precision, '0', len));
	if (p.precision < p.width && p.precision >= 0 && p.precision_char)
		return (ft_printchar((p.width - p.precision), ' ', 0));
	if (((ft_strchr("xX", p.specifier) && p.hash) || (p.specifier == 'p')))
	{
		if (p.specifier == 'X')
			return ((write(1, "0X", 2)) + (ft_printchar(p.width, '0', len)));
		return ((write(1, "0x", 2)) + (ft_printchar(p.width, '0', len)));
	}
	return (ft_printchar(p.width, '0', len));
}

int	ft_print_plus_or_space_flag(char arg, t_params p)
{
	if ((p.specifier == 'd' || p.specifier == 'i' || p.specifier == 'u')
		&& (arg != '-'))
	{
		if (arg >= '0' && arg <= '9' && p.plus_or_space == '+'
			&& p.zero_or_blank != '0')
			return (write(1, "+", 1));
		if (p.plus_or_space == ' ' && p.zero_or_blank != '0')
			return (write(1, " ", 1));
	}
	return (0);
}

int	ft_print_precision(char **arg, t_params p)
{
	int		len;

	if (p.specifier == 'c' || p.specifier == 's' || !p.precision_char)
		return (0);
	len = ft_strlen(*arg);
	if (*arg[0] == '-' && (p.specifier == 'd' || p.specifier == 'i'))
		len--;
	if (p.precision <= len)
		return (0);
	else if (*arg[0] == '-' && ft_strchr("di", p.specifier))
		return (write(1, "-", 1) + (ft_printchar((p.precision - len), '0', 0)));
	if (ft_strchr("di", p.specifier) && p.plus_or_space)
	{
		if (p.plus_or_space == ' ')
			write(1, " ", 1);
		else
			write(1, "+", 1);
	}
	return (ft_printchar((p.precision - len), '0', 0));
}
