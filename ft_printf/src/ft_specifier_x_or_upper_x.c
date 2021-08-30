/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_x_or_upper_x.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:06:59 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:06:59 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_specifier_x_or_upper_x(va_list args, t_params p)
{
	int				nbr;
	unsigned int	num;
	char			*res;

	nbr = va_arg(args, int);
	if (nbr < 0)
		num = (4294967296 + nbr);
	else
		num = nbr;
	if (!num && !p.precision && p.precision_char)
		return (ft_strdup(""));
	res = ft_hextoa(num, p.specifier);
	if (!res)
		return (NULL);
	return (res);
}
