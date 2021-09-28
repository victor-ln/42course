/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 14:06:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/23 14:06:16 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *src, int c)
{
	while (*src != c)
	{
		if (!src)
			return (NULL);
		src++;
	}
	return ((char *)src);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

char	*ft_utoa(size_t nbr)
{
	char	*str;
	size_t	size;
	size_t	temp;

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

void	init_struct(t_game *game)
{
	game->moved_nbr = 0;
	game->map.area = 1;
	game->map.height = 1;
	game->map.collects = 0;
}

int	is_limit_after_c(char *s, int c, int limit)
{
	int	i;

	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] == limit)
		return (0);
	return (1);
}
