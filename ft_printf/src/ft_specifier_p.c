/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:06:30 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:06:30 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_specifier_p(va_list args)
{
	size_t	nbr;
	char	*arg;

	nbr = va_arg(args, size_t);
	arg = ft_hextoa(nbr);
	if (!arg)
		return (NULL);
	return (arg);
}
