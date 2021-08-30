/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:05:50 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:05:50 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static char	*apply_args(t_params params, va_list args);
static void	char_zero(char *arg, char *char_zero, char specifier);
static int	total_length(char *arg, t_params p);
static int	write_arg(char *arg, int len, char char_zero);

int	ft_print_args(t_params p, va_list args)
{
	int		printed;
	int		length;
	char	c_zero;
	char	*arg;

	if (p.specifier == '%')
		return (write(1, "%", 1));
	arg = apply_args(p, args);
	if (!arg)
		return (0);
	char_zero(&arg[0], &c_zero, p.specifier);
	length = total_length(arg, p);
	printed = ft_print_zeros_or_blank_flag(p, length, &arg);
	printed += ft_print_hash_flag(p, arg);
	printed += ft_print_plus_or_space_flag(arg[0], p);
	printed += ft_print_precision(&arg, p);
	printed += write_arg(arg, ft_strlen(arg), c_zero);
	if (p.zero_or_blank == '-' && p.width > printed)
		printed += ft_printchar(p.width, ' ', printed);
	free(arg);
	return (printed);
}

static char	*apply_args(t_params p, va_list args)
{
	if (p.specifier == 'c')
		return (ft_specifier_c(args));
	else if (p.specifier == 'p')
		return (ft_specifier_p(args));
	else if (p.specifier == 's')
		return (ft_specifier_s(args, p));
	else if (p.specifier == 'u')
		return (ft_specifier_u(args, p));
	else if (p.specifier == 'd' || p.specifier == 'i')
		return (ft_specifier_d_or_i(args, p));
	else
		return (ft_specifier_x_or_upper_x(args, p));
}

void	char_zero(char *arg, char *char_zero, char specifier)
{
	*char_zero = 0;
	if (specifier == 'c')
	{
		if (arg[0] == 0)
		{
			arg[0] = '0';
			*char_zero = 1;
		}
	}
}

static int	total_length(char *arg, t_params p)
{
	int	len;

	len = ft_strlen(arg);
	if (p.specifier == 's' || p.specifier == 'c')
		return (len);
	if (p.precision > len)
		len = p.precision;
	if ((p.hash && (p.specifier == 'x' || p.specifier == 'X'))
		|| (p.specifier == 'p'))
		len += 2;
	if (((p.plus_or_space && arg[0] != '-'))
		&& (p.specifier == 'd' || p.specifier == 'i' || p.specifier == 'u'))
		len++;
	if (arg[0] == '-' && p.precision < len && p.precision < p.width
		&& p.precision_char)
		len--;
	return (len);
}

static int	write_arg(char *arg, int len, char char_zero)
{
	char	zero;

	if (char_zero == 0)
		return (write(1, arg, len));
	zero = 0;
	return (write(1, &zero, 1));
}
