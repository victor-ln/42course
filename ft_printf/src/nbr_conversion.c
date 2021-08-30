/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:05:44 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/28 02:05:44 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

static size_t	count_size(size_t num, size_t base);
static char		num_base(size_t num);

char	*ft_hextoa(size_t nbr, char specifier)
{
	char	*res;
	size_t	size;

	size = count_size(nbr, 16);
	res = (char *)malloc(size + 1);
	if (!res)
		return (NULL);
	*(res + size--) = '\0';
	while (nbr > 0)
	{
		*(res + size--) = num_base((nbr % 16));
		nbr /= 16;
	}
	if (size == 0 && res[1] == '\0')
		*(res + size) = '0';
	if (specifier == 'X')
	{
		size = -1;
		while (res[++size])
			res[size] = ft_toupper(res[size]);
	}
	return (res);
}

char	*ft_utoa(unsigned int nbr)
{
	char	*str;
	int		size;

	size = count_size(nbr, 10);
	str = (char *)malloc(size + 1);
	if (!str)
		return (NULL);
	*(str + size--) = '\0';
	while (nbr > 0)
	{
		*(str + size--) = num_base((nbr % 10));
		nbr /= 10;
	}
	if (size == 0 && str[1] == '\0')
		*(str + size) = '0';
	return (str);
}

static size_t	count_size(size_t num, size_t base)
{
	size_t	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= base;
		size++;
	}
	return (size);
}

static char	num_base(size_t num)
{
	char	*base;

	base = "0123456789abcdef";
	return (base[num]);
}
