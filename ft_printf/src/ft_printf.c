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

int	ft_printf(const char *format, ...)
{
	int			printed;
	int			option;
	va_list		args;
	t_params	params;

	printed = 0;
	va_start(args, format);
	while (*format)
	{
		option = ft_is_valid(format + 1, &params, args);
		if (!option)
			printed += (write(1, format++, 1));
		else if (option > 0)
		{
			printed += ft_print_args(params, args);
			format = ft_toward_specifier(++format);
		}
		else
			return (-1);
	}
	va_end(args);
	return (printed);
}
