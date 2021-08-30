/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier_d_or_i.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:06:20 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:06:20 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_specifier_d_or_i(va_list args, t_params params)
{
	int		num;
	char	*arg;

	num = va_arg(args, int);
	if (!params.precision && !num && params.precision_char)
		return (ft_strdup(""));
	arg = ft_itoa(num);
	if (!arg)
		return (NULL);
	return (arg);
}