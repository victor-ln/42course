/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 04:52:40 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/26 04:52:40 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_save_map
{
	char	*swap;
	char	*map;
	char	buffer[1001];
	ssize_t	size;
}	t_save_map;

static char		*save_map(int fd);
static char		*ft_strjoin(const char *s1, const char *s2);
static size_t	ft_strlen(const char *string);

char	*load_map(char *filename)
{
	int		fd;

	while (*filename)
		filename++;
	if (ft_strcmp(filename - 4, ".ber"))
		exit_game("Invalid extension\n", 1, 0);
	fd = open(filename, 00);
	if (fd < 0)
		exit_game("Invalid file\n", 1, 0);
	return (save_map(fd));
}

static char	*save_map(int fd)
{
	t_save_map	s_data;

	s_data.size = read(fd, s_data.buffer, 1000);
	s_data.map = malloc(1);
	*s_data.map = 0;
	while (s_data.size > 0)
	{
		s_data.buffer[s_data.size] = 0;
		s_data.swap = ft_strjoin(s_data.map, "");
		free(s_data.map);
		s_data.map = ft_strjoin(s_data.swap, s_data.buffer);
		free(s_data.swap);
		s_data.size = read(fd, s_data.buffer, 1000);
	}
	close(fd);
	if (!s_data.map)
		exit_game("Malloc error", 1, 0);
	return (s_data.map);
}

static size_t	ft_strlen(const char *string)
{
	size_t	i;

	i = 0;
	while (string[i])
		i++;
	return (i);
}

static char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new)
		return (NULL);
	while (*s1)
	{
		*new = *s1;
		new++;
		s1++;
	}
	while (*s2)
	{
		*new = *s2;
		new++;
		s2++;
	}
	*new = 0;
	return (new);
}
