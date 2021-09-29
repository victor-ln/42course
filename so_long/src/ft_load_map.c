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

static char	*save_map(int fd);

void	ft_load_map(char *filename, t_game *game)
{
	int		fd;

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
	game->map = save_map(fd);
	if (!game->map)
	{
		ft_putstr_fd("Error\n", 2);
		exit_game(strerror(errno), 0, game);
	}
}

static char	*save_map(int fd)
{
	char	*swap;
	char	*map;
	char	buffer[1001];
	long	size;

	size = read(fd, buffer, 1000);
	map = ft_calloc(1, 1);
	while (size > 0)
	{
		buffer[size] = 0;
		swap = strdup(map);
		free(map);
		map = ft_strjoin(swap, buffer);
		free(swap);
		size = read(fd, buffer, 1000);
	}
	close(fd);
	return (map);
}
