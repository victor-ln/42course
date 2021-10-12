/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:08:21 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 11:14:38 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	save_location(t_game *game, int *coins, int index);
static int	is_surrounded(char *map, char end);

void	map_dimension(t_game *game)
{
	int		map_len;
	int		i;

	i = 0;
	while (game->map_b[i])
	{
		if (game->map_b[i] == '\n')
			game->height++;
		else if (!game->height)
			game->width++;
		i++;
	}
	game->height++;
	map_len = (int)ft_strlen(game->map_b);
	if (!map_len)
		error(game, "Invalid map, it is empty", 0);
	if (map_len != (game->width * game->height + (game->height - 1)))
		error(game, "Invalid map, it's not symmetrical", 0);
	if (game->width == game->height)
		error(game, "Invalid map, it's not rectangular", 0);
}

void	map_validation(t_game *game)
{
	int		i;

	i = -1;
	while (ft_strchr("01CEP\n", game->map_b[++i]))
	{
		if (game->map_b[i] == '1' || game->map_b[i] == '0')
			continue ;
		else if (game->map_b[i] == 'C')
			game->coins_n++;
		else if (game->map_b[i] == 'E' && !game->exits)
			game->exits++;
		else if (game->map_b[i] == 'P' && !game->heros)
			game->heros++;
		else if (game->map_b[i] != '\n')
			break ;
		else if (game->map_b[i + 1] != '1' || game->map_b[i - 1] != '1')
			error(game, "Invalid map, it's not surrounded by walls", 0);
	}
	if (ft_strchr("EP", game->map_b[i]) || (!game->map_b[i] && !game->coins_n))
		error(game, "Invalid map, must have 1 exit, 1 player and collects", 0);
	if (game->map_b[i])
		error(game, "Invalid map, it has an invalid character", 0);
	if (!is_surrounded(game->map_b, '\n') || \
		!is_surrounded(game->map_b + i - game->width, 0))
		error(game, "Invalid map, it's not surrounded by walls", 0);
}

/*
	Runs the string till map pointer differs '1'.
	After it differs returns 1 if it's followed by end, or 0 if it isn't.
*/
static int	is_surrounded(char *map, char end)
{
	while (*map == '1')
		map++;
	return (*map == end);
}

/*

A map example:

1 1 1 1 1 \n
1 0 P C 1 \n
1 E 1 C 1 \n
1 1 1 1 1 \0

*/

void	map_matrix(t_game *game)
{
	int		columns;
	int		lines;
	int		index;
	int		coins;

	lines = 0;
	index = 0;
	coins = 0;
	while (lines < game->height)
	{
		game->map[lines] = (char *)malloc(sizeof(char) * game->width);
		if (!game->map[lines])
			error(game, "Malloc for map matrix failed", strerror(errno));
		columns = 0;
		while (columns < game->width)
		{
			save_location(game, &coins, index);
			game->map[lines][columns++] = game->map_b[index++];
		}
		index++;
		lines++;
	}
}

static void	save_location(t_game *game, int *coins, int index)
{
	if (game->map_b[index] == 'C')
	{
		game->coins[*coins].x = (index % (game->width + 1)) * 32;
		game->coins[*coins].y = (index / (game->width + 1)) * 32;
		(*coins)++;
	}
	else if (game->map_b[index] == 'E')
	{
		game->exit.x = (index % (game->width + 1)) * 32;
		game->exit.y = (index / (game->width + 1)) * 32;
	}
	else if (game->map_b[index] == 'P')
	{
		game->hero.x = (index % (game->width + 1)) * 32;
		game->hero.y = (index / (game->width + 1)) * 32;
	}
	else if (game->map_b[index] == '1')
		game->walls++;
}
