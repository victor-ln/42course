/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:21:04 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/08 04:21:04 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	size_t	i;

	i = ft_strlen(src);
	if (!c)
		return ((char *)src + i);
	while (i)
	{
		if (((char *)src)[--i] == (char)c)
			return ((char *)src + i);
	}
	return (NULL);
}
