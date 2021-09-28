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

static int	ft_size(int n)
{
	int	size;

	size = 1;
	if (n > 0)
		size = 0;
	return (size);
}

static long	ft_sign(long n)
{
	long	sign;

	sign = n;
	if (n < 0)
		sign = -n;
	return (sign);
}

static size_t	ft_size_num(size_t size2, int nbr2)
{
	while (nbr2)
	{
		nbr2 /= 10;
		size2++;
	}
	return (size2);
}

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	size_t	size;

	n = nbr;
	size = ft_size(nbr);
	n = ft_sign(n);
	size = ft_size_num(size, nbr);
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = '\0';
	while (n > 0)
	{
		*(str + size--) = n % 10 + '0';
		n /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	else if (size == 0 && str[1] != '\0')
		*(str + size) = '-';
	return (str);
}
