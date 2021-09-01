/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:01:31 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:01:31 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static t_data	*set_flags(t_data *format, t_params *p);
static t_data	*set_width(t_data *format, t_params *p, va_list args);
static t_data	*set_precision(t_data *format, t_params *p, va_list args);
static int		find_error(t_data *format, t_params *p);

int	ft_is_valid(t_data *format, t_params *p, va_list args)
{
	if (*(format - 1) == '%')
	{
		ft_start_struct(p);
		format = set_flags(&*format, p);
		format = set_width(&*format, p, args);
		if (*format == '.')
			format = set_precision(format + 1, p, args);
		if (p->precision <= LIMIT && p->width <= LIMIT && p->precision >= 0)
		{
			if (ft_strchr(TYPES, *format) && *format)
			{
				p->type = *format;
				return (1);
			}
		}
		return (find_error(&*format, p));
	}
	return (0);
}

static t_data	*set_flags(t_data *format, t_params *p)
{
	while (ft_strchr(FLAGS, *format))
	{
		if (*format == '#')
			p->hash = '#';
		if (*format == '+')
			p->plus_or_space = '+';
		if (*format == ' ' && !p->plus_or_space)
			p->plus_or_space = ' ';
		if (*format == '-')
			p->zr_or_spaces = '-';
		if (*format == '0' && !p->zr_or_spaces)
			p->zr_or_spaces = '0';
		format++;
	}
	return (format);
}

static t_data	*set_width(t_data *format, t_params *p, va_list args)
{
	if (*format == '*' && (ft_strchr(TYPES, format[1]) || format[1] == '.'))
	{
		p->width = va_arg(args, int);
		if (p->width < 0 && p->zr_or_spaces != '-')
		{
			p->width *= -1;
			p->zr_or_spaces = '-';
		}
		format++;
	}
	while (ft_isdigit(*format))
	{
		p->width = p->width * 10 + *format - 48;
		format++;
	}
	return (format);
}

static t_data	*set_precision(t_data *format, t_params *p, va_list args)
{
	p->precision_c = 1;
	if (*format == '*' && ft_strchr(TYPES, format[1]))
	{
		p->precision = va_arg(args, int);
		if (p->precision < 0)
			p->precision = 1;
		return (format += 2);
	}
	while (ft_isdigit(*format))
	{
		p->precision = p->precision * 10 + *format - 48;
		format++;
	}
	return (format);
}

static int	find_error(t_data *format, t_params *p)
{
	if (p->width > LIMIT || p->precision > LIMIT)
		return (-1);
	if (p->precision < 0)
		return (0);
	if (!format[1])
		return (-1);
	return (0);
}
