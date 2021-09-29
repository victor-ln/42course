/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:22:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/29 00:22:09 by vlima-nu         ###   ########.fr       */
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

char	*ft_load_map(char *filename, int counter)
{
	int		fd;

	if (counter != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		exit(1);
	}
	fd = open(filename, 00);
	if (fd < 0)
	{
		perror("Error\nCouldn't open the file");
		exit(1);
	}
	while (*filename)
		filename++;
	if (ft_strcmp(filename - 4, ".ber"))
	{
		ft_putstr_fd("Error\nInvalid file extension. It must be *.ber\n", 2);
		close(fd);
		exit (1);
	}
	return (save_map(fd));
}

static char	*save_map(int fd)
{
	t_save_map	data;

	data.size = read(fd, data.buffer, 1000);
	data.map = ft_calloc(1, 1);
	while (data.size > 0)
	{
		data.buffer[data.size] = 0;
		data.swap = strdup(data.map);
		free(data.map);
		data.map = ft_strjoin(data.swap, data.buffer);
		free(data.swap);
		data.size = read(fd, data.buffer, 1000);
	}
	close(fd);
	if (!data.map)
	{
		ft_putstr_fd(strerror(errno), 2);
		exit(1);
	}
	return (data.map);
}
