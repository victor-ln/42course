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
	char	*ptr;

	ptr = (char *)src;
	i = ft_strlen(src);
	if (c == '\0')
		return (ptr + i);
	while (i != 0)
	{
		if (ptr[i] == (char)c)
			return (ptr + i);
		i--;
	}
	if (src[0] == (char)c)
		return (ptr);
	return (0);
}
