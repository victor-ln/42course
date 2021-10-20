/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:54 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/20 15:28:31 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	save_hero_position(t_game *game, int x, int y);
static void	map_matrix(t_game *game);
static void	put_enemies(t_game *game);
static void	enemy_coords(t_game *game);

void	map_init(t_game *game)
{
	map_validate(game);
	map_matrix(game);
	put_enemies(game);
}

/*
	Converts the map_ber string into a map matrix, saves
	the x,y hero coordinates and frees the map_ber.
*/
static void	map_matrix(t_game *game)
{
	int		x;
	int		y;
	int		z;

	y = -1;
	z = 0;
	game->map = (char **)malloc(sizeof(char *) * game->height);
	if (!game->map)
		error(game, "Malloc to map matrix failed", strerror(errno));
	while (++y < game->height)
	{
		game->map[y] = (char *)malloc(sizeof(char) * game->width);
		x = -1;
		while (++x < game->width)
		{
			game->map[y][x] = game->map_ber[z++] - 48;
			if (game->map[y][x] == HERO)
				save_hero_position(game, x, y);
		}
		z++;
	}
	free(game->map_ber);
	game->map_ber = NULL;
}

static void	save_hero_position(t_game *game, int x, int y)
{
	ft_bzero(&game->hero, 3);
	game->hero.x = x * 32;
	game->hero.y = y * 32;
	game->hero.step = 0;
	if (x < (game->width / 2))
		game->hero.dir = RIGHT;
	else
		game->hero.dir = LEFT;
}

static void	enemy_coords(t_game *game)
{
	int		x;
	int		y;
	int		i;

	i = 0;
	y = 0;
	game->enemies = (t_players *)malloc(sizeof(t_players) * game->enemies_num);
	if (!game->enemies)
		error(game, "Malloc for enemies struct failed", strerror(errno));
	while (++y < game->height)
	{
		x = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] != ENEMY)
				continue ;
			game->enemies[i].x = x * 32;
			game->enemies[i].y = y * 32;
			game->enemies[i].step = 0;
			game->enemies[i].dir = ft_rand() % 4;
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
static void	put_enemies(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	game->enemies_num = 0;
	while (++y < game->height)
	{
		x = 0;
		while (++x < game->width)
		{
			if (game->map[y][x] || game->map[y][x + 1] || \
				game->map[y + 1][x] || game->map[y + 1][x + 1])
				continue ;
			else if ((game->map[y - 1][x] == ENEMY || \
				game->map[y - 1][x - 1] == ENEMY || \
				game->map[y][x - 1] == ENEMY))
				continue ;
			else if (game->enemies_num == 10)
				continue ;
			game->enemies_num++;
			game->map[y][x] = ENEMY;
		}
	}
	if (game->enemies_num != 0)
		enemy_coords(game);
}
