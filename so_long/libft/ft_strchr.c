/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 00:05:18 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/15 00:05:19 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char	dstc;
	char	*dsts;
	int		i;

	i = 0;
	dsts = (char *)src;
	dstc = c;
	while (dsts[i] != dstc)
	{
		if (dsts[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)dsts + i);
}
