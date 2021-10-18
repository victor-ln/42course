/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:40:17 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 15:21:53 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_valid(t_game *game, char map_point);
static int	is_border(t_game *game, int i);
static void	is_rectangular(t_game *game);

/*

A map example:

1 1 1 1 1 \n
1 0 P C 1 \n
1 0 0 C 1 \n
1 E 1 C 1 \n
1 1 1 1 1 \0

*/

void	map_validate(t_game *game)
{
	int		i;

	i = 0;
	is_rectangular(game);
	while (game->map_ber[i])
	{
		if (is_border(game, i))
		{
			if (game->map_ber[i] != '1')
				error(game, "Invalid map, it's not surrounded by walls", 0);
		}
		else
			is_valid(game, game->map_ber[i]);
		i++;
	}
	if (game->exits_num != 1 || game->heros_num != 1 || !game->coins_num)
		error(game, "Invalid map, must have 1 exit, 1 player and collects", 0);
}

/*
	Calculates the width and the height of the map and then
	checks if the map is symmetrical and rectangular.
*/
static void	is_rectangular(t_game *game)
{
	int		i;

	i = 0;
	while (game->map_ber[i])
	{
		if (game->map_ber[i] == '\n')
			game->height++;
		if (game->height == 1)
			game->width++;
		i++;
	}
	if (!i)
		error(game, "Invalid map, it is empty", 0);
	if (i != ((game->width * game->height) + (game->height - 1)))
		error(game, "Invalid map, it's not symmetrical", 0);
	if (game->width == game->height)
		error(game, "Invalid map, it's not rectangular", 0);
}

static void	is_valid(t_game *game, char map_point)
{
	if (map_point == '1' || map_point == '0')
		return ;
	else if (map_point == 'C')
		game->coins_num++;
	else if (map_point == 'E')
		game->exits_num++;
	else if (map_point == 'P')
		game->heros_num++;
	else if (map_point != '\n')
		error(game, "Invalid map, it has an invalid character", 0);
}

static int	is_border(t_game *game, int i)
{
	if (i < game->width
		|| (i % (game->width + 1) == 0)
		|| (i % (game->width + 1) == (game->width - 1))
		|| (i > (game->width + 1) * (game->height - 1)))
	{
		return (1);
	}
	return (0);
}
