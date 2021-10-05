/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:05:04 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 12:53:19 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *src, int c)
{
	char	dst_c;
	char	*dst_s;
	int		i;

	i = 0;
	dst_s = (char *)src;
	dst_c = c;
	while (dst_s[i] != dst_c)
	{
		if (!dst_s[i])
			return (NULL);
		i++;
	}
	return ((char *)dst_s + i);
}

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
