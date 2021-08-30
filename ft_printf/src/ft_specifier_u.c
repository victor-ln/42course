/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:06:49 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:06:49 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_specifier_u(va_list args, t_params p)
{
	unsigned int	nbr;
	char			*res;

	nbr = va_arg(args, unsigned int);
	if (!nbr && !p.precision && p.precision_char)
		return (ft_strdup(""));
	res = ft_utoa(nbr);
	if (!res)
		return (NULL);
	return (res);
}
