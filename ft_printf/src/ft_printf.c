/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:17:24 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/16 20:17:24 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static int	print_out(const char *format, va_list args);

int	ft_printf(const char *format, ...)
{
	int		printed;
	va_list	args;

	va_start(args, format);
	printed = print_out(format, args);
	va_end(args);
	return (printed);
}

static int	print_out(const char *format, va_list args)
{
	int			printed;
	int			option;
	t_params	params;

	printed = 0;
	while (*format)
	{
		option = ft_is_valid(&*format, &params, args);
		if (!option)
			printed += (write(1, &*format, 1));
		else if (option > 0)
		{
			printed += ft_print_args(params, args);
			format += ft_toward_specifier(&*format);
		}
		else
			return (-1);
		format++;
	}
	return (printed);
}
