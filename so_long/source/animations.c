/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:33:25 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:53:11 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_enemies *enemy, char **map);
static void	move_enemies(t_game *game);
static void	put_enemies(t_game *game);

int	animation(t_game *game)
{
	int		frames;

	frames = 0;
	while (frames < 8)
	{
		move_enemies(game);
		display_game(game, -1);
		mlx_put_image_to_window(game->display, game->screen, \
			game->coins_img[frames % 4], 0, 0);
		frames++;
	}
	return (0);
}

static void	move_enemies(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->enemies_n)
	{
		if (can_move(&game->enemies[i], game->map))
		{
			game->enemies[i].step++;
			if (game->enemies[i].step == 7)
				game->enemies[i].step = -1;
		}
		else
			game->enemies[i].moved_to = my_rand() % 4;
		i++;
	}
}

static int	can_move(t_enemies *enemy, char **map)
{
	int		x;
	int		y;
	int		to_x;
	int		to_y;

	x = enemy->x / 32;
	y = enemy->y / 32;
	to_x = 0;
	to_y = 0;
	if (enemy->moved_to == RIGHT)
		to_x = 4;
	else if (enemy->moved_to == LEFT)
		to_x = -4;
	else if (enemy->moved_to == UP)
		to_y = -4;
	else
		to_y = 4;
	if (map[y + (to_y / 4)][x + (to_x / 4)] != HERO && \
		map[y + (to_y / 4)][x + (to_x / 4)] != 0)
		return (0);
	map[y + (to_y / 4)][x + (to_x / 4)] = ENEMY;
	return (1);
}

void	display_game(t_game *game, int step)
{
	mlx_put_image_to_window(game->display, game->screen, game->map_img, 0, 0);
	if (step >= 0)
	{
		mlx_put_image_to_window(game->display, game->screen, \
			game->sprites.hero[game->moved_to]->walk[step], \
			game->hero.x, game->hero.y);
	}
	else
	{
		mlx_put_image_to_window(game->display, game->screen, \
			game->sprites.hero[game->moved_to]->idle, \
			game->hero.x, game->hero.y);
	}
	put_enemies(game);
	is_game_over(game);
	mlx_string_put(game->display, game->screen, 10, 10, 0xFFFFFF, "Moved :");
	mlx_string_put(game->display, game->screen, \
		60, 10, 0XFFFFFF, game->moves_str);
}

static void	put_enemies(t_game *game)
{
	int		i;
	int		dir;
	int		step;
	int		x;
	int		y;

	i = 0;
	while (i < game->enemies_n)
	{
		dir = game->enemies[i].moved_to;
		step = game->enemies[i].step;
		x = game->enemies[i].x;
		y = game->enemies[i].y;
		if (step >= 0)
			mlx_put_image_to_window(game->display, game->screen, \
				game->sprites.enemy[dir]->walk[step % 4], x, y);
		else
			mlx_put_image_to_window(game->display, game->screen, \
				game->sprites.enemy[dir]->idle, x, y);
		i++;
	}
}
