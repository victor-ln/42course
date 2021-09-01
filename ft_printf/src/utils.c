/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:07:08 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:07:08 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	ft_start_struct(t_params *p)
{
	p->type = 0;
	p->hash = 0;
	p->plus_or_space = 0;
	p->zr_or_spaces = 0;
	p->width = 0;
	p->precision = 0;
	p->precision_c = 0;
}

t_data	*ft_toward_specifier(const char *format)
{
	while (!ft_strchr("cspdiuxX%", *format) && *format)
		format++;
	return (format);
}

int	ft_printchar(int width, char c, int offset)
{
	int	printed;

	printed = 0;
	while (width > offset)
	{
		printed += write(1, &c, 1);
		width--;
	}
	return (printed);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
