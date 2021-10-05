/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:56:56 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 20:58:54 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(char *map, char end);
static int	map_info(t_game *game, char *map);
static int	check_input(int argc, char *argv, int *fd);

void	validate_map(t_game *game)
{
	int	status;
	int	map_length;

	map_length = (int)ft_strlen(game->map);
	status = map_info(game, game->map);
	game->width = game->area / game->height;
	if (status == 1 || !map_length)
		ft_putstr_fd(INVALID_CHAR, 2);
	else if (status == 2)
		ft_putstr_fd(N_SURROUNDED, 2);
	else if (map_length != (game->area + game->height - 1))
		ft_putstr_fd(N_RECTANGLE, 2);
	else if (game->width == game->height)
		ft_putstr_fd(N_RECTANGLE, 2);
	else if (status == 3 || !game->collects)
		ft_putstr_fd(INVALID, 2);
	else
		return ;
	free(game->map);
	exit(1);
}

static int	map_info(t_game *game, char *map)
{
	if (*map && !is_surrounded(map, '\n'))
		return (2);
	while (*map && ft_strchr(MAP, *map))
	{
		if (*map != '\n')
			game->area++;
		else if (*(map + 1) != '1' || *(map - 1) != '1')
			return (2);
		else
			game->height++;
		if (*map == 'C')
			game->collects++;
		else if (*map == 'E' && !game->exits)
			game->exits++;
		else if (*map == 'P' && !game->player_p)
			game->player_p = game->area + game->height - 2;
		else if (*map == 'P' || *map == 'E')
			return (3);
		map++;
	}
	if (!*map && !is_surrounded(map - (game->area / game->height), '\0'))
		return (2);
	else if (*map)
		return (1);
	return (0);
}

/*
	Map example:

	1	1	1	1	1	1	1	1	1	1	1	1	1	\n
	1	0	0	1	0	0	0	0	0	0	0	C	1	\n
	1	P	0	0	0	1	1	1	1	1	0	0	1	\n
	1	0	0	0	1	1	E	0	0	0	0	0	1	\n
	1	1	1	1	1	1	1	1	1	1	1	1	1	\0

	1	1	1	1	1	\n
	1	0	P	C	1	\n
	1	E	1	C	1	\n
	1	1	1	1	1	\0
*/

/*
** Runs the string till map pointer differs '1'.
** After it differs returns 1 if it's followed by end, or 0 if it isn't.
*/
static int	is_surrounded(char *map, char end)
{
	while (*map == '1')
		map++;
	return (*map == end);
}

void	load_map(t_game *game, int argc, char *argv)
{
	char	*swap;
	char	buffer[501];
	ssize_t	size;
	int		fd;

	if (check_input(argc, argv, &fd))
	{
		free(game);
		exit(1);
	}
	game->map = malloc(sizeof(char));
	if (!game->map)
		error(game, "Malloc for map failed\n", errno);
	*game->map = '\0';
	size = read(fd, buffer, 500);
	while (size > 0)
	{
		buffer[size] = '\0';
		swap = ft_strjoin(game->map, "\0");
		free(game->map);
		game->map = ft_strjoin(swap, buffer);
		free(swap);
		size = read(fd, buffer, 500);
	}
	close(fd);
}

int	check_input(int argc, char *argv, int *fd)
{
	*fd = open(argv, 00);
	if (argc != 2)
		perror("Error\nInvalid number of arguments");
	else if (*fd < 0)
		perror("Error\nCould not open the file");
	else if (ft_strcmp(".ber", argv + (ft_strlen(argv) - 4)))
		ft_putstr_fd("Error\nInvalid file extension. It must be *.ber\n", 2);
	else
		return (0);
	return (1);
}
