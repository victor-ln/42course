/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 20:13:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/28 20:13:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_utoa(unsigned int nbr)
{
	char			*str;
	unsigned int	size;
	unsigned int	temp;

	size = 0;
	temp = nbr;
	while (temp || !size)
	{
		temp /= 10;
		size++;
	}
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	*(str + size--) = 0;
	while (nbr)
	{
		*(str + size--) = nbr % 10 + 48;
		nbr /= 10;
	}
	if (!size && !str[1])
		str[0] = '0';
	return (str);
}
