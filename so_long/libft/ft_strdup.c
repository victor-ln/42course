/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:20:38 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/08 04:20:38 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *string)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!string)
		return (NULL);
	new_str = (char *)malloc(ft_strlen(string) + 1);
	if (!new_str)
		return (NULL);
	while (string[i])
	{
		new_str[i] = string[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
