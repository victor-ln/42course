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

void	ft_bzero(void *s, size_t n);

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
	while (temp || (!temp && !size))
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

void	init_structs(t_game *game)
{
	game->moved_nbr = 0;
	game->moved_str = 0;
	game->map.map = 0;
	game->mlx = 0;
	game->map.x = 1;
	game->map.y = 1;
	ft_bzero(&game->map, 5);
	ft_bzero(&game->sprites, 5);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	index;

	index = 0;
	while (index < n)
	{
		((char *)s)[index] = (char)0;
		index++;
	}
}
