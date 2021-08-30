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

static int	set_flags(char *format, t_params *p);
static int	find_error(char *format, t_params *p);
static int	set_width(char *format, t_params *p, va_list args);
static int	set_precision(char *format, t_params *p, va_list args);

int	ft_is_valid(char *format, t_params *p, va_list args)
{
	if (*format == '%')
	{
		format++;
		ft_start_struct(p);
		format += set_flags(&*format, p);
		format += set_width(&*format, p, args);
		if (*format == '.')
			format += set_precision(&*format, p, args);
		if (p->precision <= LIMIT && p->width <= LIMIT
			&& p->precision >= 0 && p->width >= (-LIMIT))
		{
			if (ft_strchr("cspdiuxX%", *format) && *format)
			{
				p->specifier = *format;
				return (1);
			}
		}
		return (find_error(&*format, p));
	}
	return (0);
}

static int	set_flags(char *format, t_params *p)
{
	int	i;

	i = 0;
	while (ft_strchr("# +0-", *format))
	{
		if (*format == '#')
			p->hash = '#';
		if (*format == '+')
			p->plus_or_space = '+';
		if (*format == ' ' && !p->plus_or_space)
			p->plus_or_space = ' ';
		if (*format == '-')
			p->zero_or_blank = '-';
		if (*format == '0' && p->zero_or_blank != '-')
			if (*(format + 1) >= 1 && *(format + 1) <= '9')
				p->zero_or_blank = '0';
		i++;
		format++;
	}
	return (i);
}

static int	set_width(char *format, t_params *p, va_list args)
{
	int	i;

	i = 0;
	if (*format >= '0' && *format <= '9')
	{
		while (ft_strchr("0123456789", format[i]))
			i++;
		if (ft_strchr(".cspdiuxX%", format[i]))
			p->width = atoi(format);
	}
	else if (*format == '*' && ft_strchr(".cspdiuxX%", *(format + 1)))
	{
		p->width = va_arg(args, int);
		if (p->width < 0 && p->zero_or_blank != '-')
		{
			p->width *= -1;
			p->zero_or_blank = '-';
		}
		i++;
	}
	return (i);
}

static int	find_error(char *format, t_params *p)
{
	int	i;

	i = 0;
	if (p->width > LIMIT || p->precision > LIMIT || p->width < (-LIMIT))
		return (-1);
	if (p->precision < 0)
		return (0);
	if (!format[i + 1])
		return (-1);
	return (0);
}

static int	set_precision(char *format, t_params *p, va_list args)
{
	int	i;

	i = 1;
	p->precision_char = '1';
	if (*format == '.' && format[1] == '*' && ft_strchr("cspdiuxX%", format[2]))
	{
		p->precision = va_arg(args, int);
		if (p->precision < 0)
			p->precision = 1;
		return (2);
	}
	else if (*format == '.' && ft_strchr("-0123456789", format[i]))
	{
		while (ft_strchr("-0123456789", format[i]))
			i++;
		if (format[i] != '*')
		{
			p->precision = ft_atoi(++format);
			return (i);
		}
	}
	return (1);
}
