/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
<<<<<<< HEAD:so_long/src/enemy.c
/*   Updated: 2021/10/27 01:44:50 by vlima-nu         ###   ########.fr       */
=======
/*   Updated: 2021/10/25 19:51:50 by vlima-nu         ###   ########.fr       */
>>>>>>> 43479e832814406b84f9ea2af72729d193f9e129:so_long/src/animations.c
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_can_move(t_enemies *enemy, char **map);

void	move_enemies(t_game *game)
{
	register int		i;

	i = -1;
	while (++i < game->enemies_num)
	{
		if (game->enemies[i].is_alive != 1)
			continue ;
		if (!enemy_can_move(game->enemies + i, game->map))
		{
			game->enemies[i].dir = ft_rand() % 4;
			game->enemies[i].step = 0;
		}
		else if (++game->enemies[i].steps <= 8)
		{
			if (++game->enemies[i].step == 5)
				game->enemies[i].step = 1;
			game->enemies[i].x += game->enemies[i].to_x;
			game->enemies[i].y += game->enemies[i].to_y;
		}
		else
			game->enemies[i].steps = 0;
	}
}

static int	enemy_can_move(t_enemies *enemy, char **map)
{
	int		x;
	int		y;

	if (!enemy->steps)
	{
		x = enemy->x / 32;
		y = enemy->y / 32;
		enemy->to_x = 0;
		enemy->to_y = 0;
		if (enemy->dir == RIGHT)
			enemy->to_x = 4;
		else if (enemy->dir == LEFT)
			enemy->to_x = -4;
		else if (enemy->dir == UP)
			enemy->to_y = -4;
		else
<<<<<<< HEAD:so_long/src/enemy.c
			enemy->to_y = 1;
		if (map[y + enemy->to_y][x + enemy->to_x])
=======
			enemy->to_y = 4;
		if (map[y + enemy->to_y / 4][x + enemy->to_x / 4])
>>>>>>> 43479e832814406b84f9ea2af72729d193f9e129:so_long/src/animations.c
			return (0);
		map[y][x] = 0;
		map[y + enemy->to_y / 4][x + enemy->to_x / 4] = ENEMY;
	}
	return (1);
}

void	enemy_death(t_game *game, int i)
{
	draw_sprite(game->img, \
		game->sprites.enemy_death[game->enemies[i].step], \
		game->enemies[i].x, game->enemies[i].y);
	if (++game->enemies[i].step == 6)
	{
		game->enemies[i].x = 0;
		game->enemies[i].y = 0;
		game->enemies[i].is_alive = 0;
		game->kills++;
	}
}
