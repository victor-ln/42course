/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/25 08:27:06 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_can_move(t_enemies *enemy, char **map);

int	animation(t_game *game)
{
	if (BONUS)
		display_game(game);
	game->hero.step = 0;
	return (0);
}

void	move_enemies(t_game *game)
{
	register int		i;

	i = 0;
	while (i < game->enemies_num)
	{
		if (!enemy_can_move(game->enemies + i, game->map))
		{
			game->enemies[i].dir = ft_rand() % 4;
			game->enemies[i].step = 0;
		}
		else if (++game->enemies[i].steps <= 8)
		{
			if (++game->enemies[i].step == 5)
				game->enemies[i].step = 1;
			game->enemies[i].x += (game->enemies[i].to_x * 4);
			game->enemies[i].y += (game->enemies[i].to_y * 4);
		}
		else
			game->enemies[i].steps = 0;
		i++;
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
			enemy->to_x = 1;
		else if (enemy->dir == LEFT)
			enemy->to_x = -1;
		else if (enemy->dir == UP)
			enemy->to_y = -1;
		else
			enemy->to_y = 1;
		if (map[y + enemy->to_y][x + enemy->to_x] != HERO && \
			map[y + enemy->to_y][x + enemy->to_x])
			return (0);
		map[y][x] = 0;
		map[y + enemy->to_y][x + enemy->to_x] = ENEMY;
	}
	return (1);
}

void	display_game(t_game *game)
{
	move_enemies(game);
	draw_game(game);
	mlx_put_image_to_window(game->mlx, game->screen, game->img, 0, 0);
	if (BONUS)
	{
		if (++game->frame == 8)
			game->frame = 0;
		ft_delay(46500);
		mlx_string_put(game->mlx, game->screen, 10, 10, C_WHITE, "Moves :");
		mlx_string_put(game->mlx, game->screen, 60, 10, C_WHITE, \
			game->moves_str);
		hero_got_caught(game);
	}
}
