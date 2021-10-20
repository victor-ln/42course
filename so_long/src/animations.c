/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/20 15:44:55 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_can_move(t_game *game, int i);

int	animation(t_game *game)
{
	move_enemies(game);
	display_game(game);
	return (0);
}

void	move_enemies(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemies_num)
	{
		if (!enemy_can_move(game, i))
			game->enemies[i].dir = ft_rand() % 4;
		else
		{
			if (++game->enemies[i].step <= 8)
			{
				game->enemies[i].x += (game->enemies[i].to_x * 4);
				game->enemies[i].y += (game->enemies[i].to_y * 4);
			}
			else
				game->enemies[i].step = 0;
		}
		i++;
	}
}

static int	enemy_can_move(t_game *game, int i)
{
	int		x;
	int		y;

	x = game->enemies[i].x / 32;
	y = game->enemies[i].y / 32;
	if (!game->enemies[i].step)
	{
		game->enemies[i].to_x = 0;
		game->enemies[i].to_y = 0;
		if (game->enemies[i].dir == RIGHT)
			game->enemies[i].to_x = 1;
		else if (game->enemies[i].dir == LEFT)
			game->enemies[i].to_x = -1;
		else if (game->enemies[i].dir == UP)
			game->enemies[i].to_y = -1;
		else
			game->enemies[i].to_y = 1;
		if (game->map[y + game->enemies[i].to_y][x + game->enemies[i].to_x] != HERO && \
			game->map[y + game->enemies[i].to_y][x + game->enemies[i].to_x] != 0)
			return (0);
		game->map[y][x] = 0;
		game->map[y + game->enemies[i].to_y][x + game->enemies[i].to_x] = ENEMY;
	}
	return (1);
}
