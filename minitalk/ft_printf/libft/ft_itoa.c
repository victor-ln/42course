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

static int	size_num(int nbr);

char	*ft_itoa(int nbr)
{
	char	*str;
	long	n;
	int		size;

	size = size_num(nbr);
	if (nbr < 0)
		n = -nbr;
	else
		n = nbr;
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = 0;
	while (n)
	{
		*(str + size--) = n % 10 + '0';
		n /= 10;
	}
	if (!size && !str[1])
		*(str + size) = '0';
	else if (!size && str[1])
		*(str + size) = '-';
	return (str);
}

static int	size_num(int nbr)
{
	int		size;

	size = 0;
	if (nbr < 0)
		size = 1;
	while (nbr || !size)
	{
		nbr /= 10;
		size++;
	}
	return (size);
}
