/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:18:43 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/08 04:18:43 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static ssize_t	check_entire_set(char const s1, char const *set)
{
	while (*set)
	{
		if (*set == s1)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	ssize_t	i;
	ssize_t	j;

	if (!(s1) || !(set))
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s1) - 1;
	while (check_entire_set(s1[i], set) && s1[i] != '\0')
		i++;
	while (check_entire_set(s1[j], set) && j != 0)
		j--;
	if ((j - i + 1) <= 0)
		return (ft_calloc(1, 1));
	return (ft_substr(s1, i, (j - i + 1)));
}
