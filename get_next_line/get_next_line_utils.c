/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:24:20 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/11 18:24:20 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return (0);
	while (string[i] != '\0')
		i++;
	return (i);
}

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
	while (string[i] != '\0')
	{
		new_str[i] = string[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	new_str = (char *)malloc((ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (!new_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		new_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		new_str[i + j] = s2[j];
		j++;
	}
	new_str[i + j] = '\0';
	return (new_str);
}

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
	char			*new_str;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	new_str = NULL;
	new_str = ft_secure_malloc(new_str, start, s_len, len);
	if (!s || (new_str == NULL))
		return (NULL);
	i = 0;
	while ((i < len) && ((start + i) < s_len) && (s[start + i] != '\0'))
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
