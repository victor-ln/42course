/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:35:56 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 11:16:49 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned short	g_lfsr = 0xACE1u;;
unsigned int	g_bit;

unsigned int	my_rand(void)
{
	g_bit = ((g_lfsr >> 0) ^ (g_lfsr >> 2) ^ (g_lfsr >> 3) ^ (g_lfsr >> 5)) & 1;
	g_lfsr = (g_lfsr >> 1) | (g_bit << 15);
	return (g_lfsr);
}

void	load_map(t_game *game, int fd)
{
	char	*swap;
	char	buffer[501];
	ssize_t	size;

	game->map_b = ft_calloc(sizeof(char), 1);
	if (fd < 0)
		error(game, 0, 0);
	if (!game->map_b)
		error(game, "Malloc for map failed", strerror(errno));
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
	if (!game->map_b)
		error(game, "Malloc for map failed", strerror(errno));
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
		ft_putendl_fd("Error\nInvalid file extension. It must be *.ber", 2);
	else
		return (fd);
	return (-1);
}

int	enemy_can_play(t_game *game)
{
	if (((game->height * game->width) - (2 + game->walls + game->coins_n)))
		return (0);
	return (1);
}
