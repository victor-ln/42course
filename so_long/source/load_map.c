/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 14:55:06 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 17:39:58 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *game, int fd)
{
	char	*swap;
	char	buffer[501];
	ssize_t	size;

	game->map_b = malloc(sizeof(char));
	if (!game->map_b)
		error(game, "Malloc for map failed\n", strerror(errno));
	*game->map_b = 0;
	size = read(fd, buffer, 500);
	while (size > 0)
	{
		buffer[size] = 0;
		swap = ft_strdup(game->map_b);
		free(game->map_b);
		game->map_b = ft_strjoin(swap, buffer);
		free(swap);
		size = read(fd, buffer, 500);
	}
	close(fd);
}

int	check_input(int argc, char *argv)
{
	int	fd;

	fd = open(argv, 00);
	if (argc != 2)
		perror("Error\nInvalid number of arguments");
	else if (fd < 0)
		perror("Error\nCould not open the file");
	else if (ft_strcmp(".ber", argv + (ft_strlen(argv) - 4)))
		ft_putstr_fd("Error\nInvalid file extension. It must be *.ber\n", 2);
	else
		return (fd);
	return (-1);
}
