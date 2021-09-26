/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:19:28 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/08 04:19:28 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_sign(long n)
{
	long	sign;

	sign = n;
	if (n < 0)
		sign = -n;
	return (sign);
}

static size_t	ft_size_num(size_t size, int nbr)
{
	if (!nbr)
		return (1);
	if (nbr < 0)
		size++;
	while (nbr)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	size_t	size;

	size = ft_size_num(0, nbr);
	n = ft_sign(nbr);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = 0;
	while (n)
	{
		*(str + size--) = n % 10 + 48;
		n /= 10;
	}
	if (!size && !str[1])
		*(str + size) = 48;
	else if (!size && str[1])
		*(str + size) = 45;
	return (str);
}
