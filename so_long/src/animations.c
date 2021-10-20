/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/19 22:36:41 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_enemies(t_game *game);
static int	enemy_can_move(t_players *enemy, char **map);

int	animation(t_game *game)
{
	if (game->frame == 4)
		game->frame = 0;
	move_enemies(game);
	display_game(game);
	hero_got_caught(game);
	game->frame++;
	return (0);
}

static void	move_enemies(t_game *game)
{
	int		i;

	i = -1;
	while (++i < game->enemies_num)
	{
		if (!enemy_can_move(&game->enemies[i], game->map))
			game->enemies[i].dir = ft_rand() % 4;
		else
		{
			game->enemies[i].step++;
			game->enemies[i].x += (game->enemies[i].to_x * 8);
			game->enemies[i].y += (game->enemies[i].to_y * 8);
			if (game->enemies[i].step == 5)
				game->enemies[i].step = 0;
		}
	}
}

static int	enemy_can_move(t_players *enemy, char **map)
{
	int		x;
	int		y;

	x = enemy->x / 32;
	y = enemy->y / 32;
	if (!enemy->step)
	{
		ft_bzero(enemy, 2);
		if (enemy->dir == RIGHT)
			enemy->to_x = 1;
		else if (enemy->dir == LEFT)
			enemy->to_x = -1;
		else if (enemy->dir == UP)
			enemy->to_y = -1;
		else
			enemy->to_y = 1;
		if (map[y + enemy->to_y][x + enemy->to_x] != HERO && \
			map[y + enemy->to_y][x + enemy->to_x] != 0)
			return (0);
		map[y + enemy->to_y][x + enemy->to_x] = ENEMY;
	}
	return (1);
}
