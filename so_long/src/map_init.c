/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:43:54 by vlima-nu          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/10/27 02:54:37 by vlima-nu         ###   ########.fr       */
=======
/*   Updated: 2021/10/25 18:37:53 by vlima-nu         ###   ########.fr       */
>>>>>>> 43479e832814406b84f9ea2af72729d193f9e129
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	hero_coords(t_game *game, int x, int y);
static void	map_matrix(t_game *game);
static void	put_enemies(t_game *game);
static void	enemy_coords(t_game *game);

void	map_init(t_game *game)
{
	map_validate(game);
	map_matrix(game);
	free(game->map_ber);
	game->map_ber = 0;
	if (BONUS)
	{
		put_enemies(game);
		if (game->enemies_num)
		{
			game->enemies = (t_enemies *)malloc(sizeof(t_enemies) * \
				game->enemies_num);
			if (!game->enemies)
				error(game, "Malloc for enemies struct failed", \
					strerror(errno));
			enemy_coords(game);
		}
	}
}

/*
	Converts the map_ber string into a map matrix, saves
	the x, y hero coordinates and frees the map_ber.
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
				hero_coords(game, x, y);
		}
		z++;
	}
}

static void	hero_coords(t_game *game, int x, int y)
{
	game->hero.x = x * 32;
	game->hero.y = y * 32;
	game->hero.step = 0;
	if (x < (game->width / 2))
		game->hero.dir = RIGHT;
	else
		game->hero.dir = LEFT;
	game->map[y][x] = 0;
}

static void	enemy_coords(t_game *game)
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
			ft_bzero(game->enemies + i, sizeof(t_enemies));
			game->enemies[i].x = x * 32;
			game->enemies[i].y = y * 32;
			game->enemies[i].is_alive = 1;
			game->enemies[i].who = ft_rand() % 2;
			game->enemies[i].dir = ft_rand() % 4;
			i++;
		}
	}
}

/*
	In the follow map just one enemy
	can exist on 1, 1 position.

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
static void	put_enemies(t_game *g)
{
	int		x;
	int		y;

	y = 0;
	while (++y < g->height)
	{
		x = 0;
		while (++x < g->width)
		{
			if (g->map[y][x] || g->map[y][x + 1] == 1 || \
				g->map[y + 1][x] == 1 || g->map[y + 1][x + 1] == 1)
				continue ;
			else if ((g->map[y - 1][x] == ENEMY || \
				g->map[y - 1][x - 1] == ENEMY || g->map[y][x - 1] == ENEMY))
				continue ;
			else if (g->enemies_num == (((g->width - 2) + (g->height - 2)) / 3))
				break ;
			g->enemies_num++;
			g->map[y][x] = ENEMY;
		}
	}
}
