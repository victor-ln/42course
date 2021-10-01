/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:56:56 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/01 04:33:25 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(char *map);
static int	map_info(t_game *game, char *map);
static int	check_input(int argc, char *argv);

void	validate_map(t_game *game)
{
	int	status;
	int	map_length;

	status = map_info(game, game->map);
	map_length = (int)ft_strlen(game->map);
	game->width = game->area / game->height;
	if (status == 1 || !map_length)
		map_error(INVALID_CHAR, game->map);
	if (status == 2)
		map_error(N_SURROUNDED, game->map);
	if (map_length != (game->area + game->height))
		map_error(N_RECTANGLE, game->map);
	if (game->width == game->height)
		map_error(N_RECTANGLE, game->map);
	if (status == 3 || !game->collects)
		map_error(N_VALID, game->map);
}

static int	map_info(t_game *game, char *map)
{
	if (!is_surrounded(map) && *map)
		return (2);
	while (ft_strchr(MAP, *map) && *map)
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
			game->player_p = game->area / game->height;
		else if (*map == 'P' || *map == 'E')
			return (3);
		map++;
	}
	if (*map != '\0')
		return (1);
	if (game->area && !is_surrounded(map - (game->area / game->height)))
		return (2);
	return (0);
}

/*
** Runs the string till map pointer differs '1'.
** After it differs returns 1 if it's followed by '\0' or '\n', or 0 if it isn't.
*/
static int	is_surrounded(char *map)
{
	while (*map == '1')
		map++;
	return (*map == '\n' || *map == '\0');
}

void	load_map(char **map, int argc, char *argv)
{
	char	*swap;
	char	buffer[501];
	ssize_t	size;
	int		fd;

	fd = check_input(argc, argv);
	*map = malloc(sizeof(char));
	if (*map == NULL)
		primary_errors("Malloc for map failed\n", strerror(errno));
	*map[0] = '\0';
	size = read(fd, buffer, 500);
	while (size > 0)
	{
		buffer[size] = '\0';
		swap = ft_strjoin(*map, "\0");
		free(*map);
		*map = ft_strjoin(swap, buffer);
		free(swap);
		size = read(fd, buffer, 500);
	}
	close(fd);
}

static int	check_input(int argc, char *argv)
{
	int	fd;

	if (argc != 2)
		primary_errors("Invalid number of arguments\n", strerror(errno));
	fd = open(argv, 00);
	if (fd < 0)
		primary_errors("Could not open the file\n", strerror(errno));
	while (*argv)
		argv++;
	if (ft_strcmp(".ber", argv - 4))
		primary_errors("Invalid file extension. It must be *.ber\n", NULL);
	return (fd);
}
