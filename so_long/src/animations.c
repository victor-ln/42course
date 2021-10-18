/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 17:48:13 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_players(t_game *game);
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

	i = 0;
	while (i < game->enemies_num)
	{
		if (!enemy_can_move(&game->enemies[i], game->map))
			game->enemies[i].dir = ft_rand() % 4;
		else
		{
			game->enemies[i].step++;
			if (game->enemies[i].step == 5)
				game->enemies[i].step = 0;
		}
		i++;
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
	enemy->x += (enemy->to_x * 8);
	enemy->y += (enemy->to_y * 8);
	return (1);
}

void	display_game(t_game *game)
{
	draw_game(game);
	draw_players(game);
	mlx_put_image_to_window(game->mlx, game->screen, game->img, 0, 0);
	mlx_string_put(game->mlx, game->screen, 10, 10, C_WHITE, "Moved :");
	mlx_string_put(game->mlx, game->screen, 60, 10, C_WHITE, game->moves_str);
}

void	draw_players(t_game *game)
{
	int		i;

	i = 0;
	draw_sprite(game->img, game->sprites.hero[game->hero.dir][game->hero.step], \
		game->hero.x, game->hero.y);
	while (i < game->enemies_num)
	{
		draw_sprite(game->img, \
			game->sprites.enemy[game->enemies[i].dir][game->enemies[i].step], \
			game->enemies[i].x, game->enemies[i].y);
		i++;
	}
}
