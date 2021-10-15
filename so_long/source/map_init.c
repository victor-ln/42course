/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:54 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:55:48 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	save_coord(t_game *game, int *coins, int x, int y);
static void	enemies_possibilities(t_game *game);
static void	get_enemy_coords(t_game *game);
static void	map_matrix(t_game *game);

void	map_init(t_game *game)
{
	map_dimension(game);
	map_validation(game);
	game->map = (char **)malloc(sizeof(char *) * game->height);
	game->coins = (t_coord *)malloc(sizeof(t_coord) * game->coins_n);
	if (!game->map || !game->coins)
		error(game, "Malloc to map/coins matrix failed", strerror(errno));
	map_matrix(game);
	free(game->map_b);
	game->map_b = 0;
	game->moves_str = ft_utoa(0);
	enemies_possibilities(game);
	if (!game->enemies_n)
		return ;
	game->enemies = (t_enemies *)malloc(sizeof(t_enemies) * game->enemies_n);
	get_enemy_coords(game);
}

/*
	Converts the map_b string into a map matrix, and saves the coordinates x,y in the
	collects, hero and exit coordinates structs accordingly.
*/
static void	map_matrix(t_game *game)
{
	int		x;
	int		y;
	int		z;
	int		coins;

	y = 0;
	z = 0;
	coins = 0;
	while (y < game->height)
	{
		game->map[y] = (char *)malloc(sizeof(char) * game->width);
		if (!game->map[y])
			error(game, "Malloc to map matrix failed", strerror(errno));
		x = 0;
		while (x < game->width)
		{
			game->map[y][x] = game->map_b[z] - 48;
			save_coord(game, &coins, x, y);
			z++;
			x++;
		}
		z++;
		y++;
	}
}

static void	save_coord(t_game *g, int *coins, int x, int y)
{
	if (g->map[y][x] == COLL)
	{
		g->coins[*coins].x = x * 32;
		g->coins[*coins].y = y * 32;
		(*coins)++;
	}
	else if (g->map[y][x] == EXIT)
	{
		g->exit.x = x * 32;
		g->exit.y = y * 32;
	}
	else if (g->map[y][x] == HERO)
	{
		g->hero.x = x * 32;
		g->hero.y = y * 32;
		if (x < (g->width / 2))
			g->moved_to = RIGHT;
		else
			g->moved_to = LEFT;
	}
}

static void	get_enemy_coords(t_game *game)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	while (++y < game->height)
	{
		x = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] != ENEMY)
				continue ;
			game->enemies[i].x = x * 32;
			game->enemies[i].y = y * 32;
			if (x < (game->width / 2))
				game->enemies[i].moved_to = RIGHT;
			else
				game->enemies[i].moved_to = LEFT;
			game->enemies[i].step = -1;
			i++;
		}
	}
}

/*
	In the follow map just one enemy
	can exist on map[1][1] position.

		0 1 2 3 4

	0	1 1 1 1 1 \n
	1	1 0 0 C 1 \n
	2	1 0 0 C 1 \n
	3	1 E 1 P 1 \n
	4	1 1 1 1 1 \0
*/

/*
	Searches in the map free spaces to put enemies.
*/
static void	enemies_possibilities(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (++y < game->height)
	{
		x = 0;
		while (++x < game->width)
		{
			if (game->map[y][x])
				continue ;
			if ((((!game->map[y + 1][x] && !game->map[y + 1][x + 1]) || \
				(!game->map[y - 1][x] && !game->map[y - 1][x + 1])) && \
				(!game->map[y][x + 1])) || \
				(((!game->map[y + 1][x] && !game->map[y + 1][x - 1]) || \
				(!game->map[y - 1][x] && !game->map[y - 1][x - 1])) && \
				(!game->map[y][x - 1])))
			{
				game->enemies_n++;
				game->map[y][x] = ENEMY;
			}
		}
	}
}
