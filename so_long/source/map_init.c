/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:08:21 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 21:07:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_surrounded(char *map, char end);
static void	map_dimension(t_game *game);
static void	map_validate(t_game *game);
static void	map_matrix(t_game *game);

static void	map_dimension(t_game *game)
{
	int		map_len;
	int		x;

	x = 0;
	while (game->map_b[x] != '\n')
	{
		game->width++;
		x++;
	}
	while (game->map_b[x])
	{
		if (game->map_b[x] == '\n')
			game->height++;
		x++;
	}
	if (!game->map_b[x] && game->map_b[x - 1] != '\n')
		game->height++;
	map_len = (int)ft_strlen(game->map_b);
	if (!map_len)
		error(game, EMPTY, 0);
	if (map_len != (game->width * game->height + game->height))
		error(game, N_SYMMETRIC, 0);
	if (game->width == game->height)
		error(game, N_RECTANGLE, 0);
}

static void	map_validate(t_game *game)
{
	int	i;

	i = -1;
	if (!is_surrounded(game->map_b, '\n'))
		error(game, N_SURROUNDED, 0);
	while (ft_strchr(MAP, game->map_b[++i]))
	{
		if (game->map_b[i] == '1' || game->map_b[i] == '0')
			continue ;
		else if (game->map_b[i] == 'C')
			game->collects++;
		else if (game->map_b[i] == 'E' && game->exit_p == 0)
			game->exit_p = i;
		else if (game->map_b[i] == 'P' && game->player_p == 0)
			game->player_p = i;
		else if (game->map_b[i] != '\n')
			error(game, INVALID, 0);
		else if (game->map_b[i + 1] != '1' || game->map_b[i - 1] != '1')
			error(game, N_SURROUNDED, 0);
	}
	if (game->map_b[i] == 0 && !is_surrounded(game->map_b + i - game->width, 0))
		error(game, N_SURROUNDED, 0);
	if (game->map_b[i] != 0)
		error(game, INVALID_CHAR, 0);
}

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

/*
	A map example:

	1	1	1	1	1	\n
	1	0	P	C	1	\n
	1	E	1	C	1	\n
	1	1	1	1	1	\0
*/

static void	map_matrix(t_game *game)
{
	int	x;
	int	y;
	int	z;

	y = -1;
	z = -1;
	game->map = (char **)malloc_matrix(sizeof(char) * game->width, \
		sizeof(char *) * game->height);
	if (!game->map)
		error(game, "Malloc for map matrix failed\n", strerror(errno));
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			game->map[y][x] = game->map_b[++z];
		z++;
	}
	free(game->map_b);
	game->map_b = 0;
}

void	map_init(t_game *game)
{
	map_dimension(game);
	map_validate(game);
	if (game->collects < 1)
		error(game, INVALID, 0);
	game->player.x = game->player_p % (game->width + 1);
	game->player.y = game->player_p / (game->width + 1);
	game->exit.x = game->exit_p % (game->width + 1);
	game->exit.y = game->exit_p / (game->width + 1);
	map_matrix(game);
}
