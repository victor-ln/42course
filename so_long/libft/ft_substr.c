/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:21:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/08 04:21:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_secure_malloc(char *ptr, size_t start,
		unsigned int s_len, size_t len)
{
	if (start >= s_len)
		ptr = malloc(sizeof(char) * 1);
	else if (len > s_len - start)
		ptr = malloc(sizeof(char) * (s_len - start + 1));
	else
		ptr = malloc(sizeof(char) * (len + 1));
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	unsigned int	s_len;
	char			*new_string;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	new_string = NULL;
	new_string = ft_secure_malloc(new_string, start, s_len, len);
	if (!s || (new_string == NULL))
		return (NULL);
	i = 0;
	while ((i < len) && ((start + i) < s_len) && (s[start + i] != '\0'))
	{
		new_string[i] = s[start + i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
