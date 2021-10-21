/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/21 03:36:28 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	enemy_can_move(t_game *game, int i);

int	animation(t_game *game)
{
	if (BONUS)
	{
		move_enemies(game);
		display_game(game);
	}
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
		else if (++game->enemies[i].step <= 8)
		{
			game->enemies[i].x += (game->enemies[i].to_x * 4);
			game->enemies[i].y += (game->enemies[i].to_y * 4);
		}
		else
			game->enemies[i].step = 0;
		i++;
	}
}

static int	enemy_can_move(t_game *g, int i)
{
	int		x;
	int		y;

	x = g->enemies[i].x / 32;
	y = g->enemies[i].y / 32;
	if (!g->enemies[i].step)
	{
		g->enemies[i].to_x = 0;
		g->enemies[i].to_y = 0;
		if (g->enemies[i].dir == RIGHT)
			g->enemies[i].to_x = 1;
		else if (g->enemies[i].dir == LEFT)
			g->enemies[i].to_x = -1;
		else if (g->enemies[i].dir == UP)
			g->enemies[i].to_y = -1;
		else
			g->enemies[i].to_y = 1;
		if (g->map[y + g->enemies[i].to_y][x + g->enemies[i].to_x] != HERO
			&& g->map[y + g->enemies[i].to_y][x + g->enemies[i].to_x])
			return (0);
		g->map[y][x] = 0;
		g->map[y + g->enemies[i].to_y][x + g->enemies[i].to_x] = ENEMY;
	}
	return (1);
}

void	display_game(t_game *game)
{
	draw_game(game);
	mlx_put_image_to_window(game->mlx, game->screen, game->img, 0, 0);
	if (BONUS)
	{
		if (++game->frame == 4)
			game->frame = 0;
		ft_delay(46000);
		mlx_string_put(game->mlx, game->screen, 10, 10, C_WHITE, "Moved :");
		mlx_string_put(game->mlx, game->screen, 60, 10, C_WHITE, \
			game->moves_str);
	}
	else if (game->hero.step == 6)
		ft_putendl_fd(game->moves_str, 1);
	hero_got_caught(game);
}
