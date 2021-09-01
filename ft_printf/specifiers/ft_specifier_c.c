/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:06:10 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:06:10 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_specifier_c(va_list args)
{
	char	*arg;

	arg = (char *)malloc(sizeof(char) * 1 + 1);
	if (!arg)
		return (NULL);
	*arg = va_arg(args, int);
	*(arg + 1) = 0;
	return (arg);
}
