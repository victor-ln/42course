/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:41:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/27 02:33:32 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	apply_changes(t_game *game);
static void	move_player(t_game *game, short dir, int to_x, int to_y);
static void	shoot_arrow(t_game *game);

int	key_press(int keycode, t_game *game)
{
	if (keycode == 'd')
		move_player(game, RIGHT, 1, 0);
	else if (keycode == 'a')
		move_player(game, LEFT, -1, 0);
	else if (keycode == 's')
		move_player(game, DOWN, 0, 1);
	else if (keycode == 'w')
		move_player(game, UP, 0, -1);
	else if (keycode == ' ')
		shoot_arrow(game);
	else if (keycode == ESC)
		exit_game(game, 0);
	return (0);
}

static void	move_player(t_game *game, short dir, int to_x, int to_y)
{
	int		steps;

	game->hero.dir = dir;
	if (game->map[game->hero.y / 32 + to_y][game->hero.x / 32 + to_x] != 1)
	{
		steps = 0;
		while (steps <= 7)
		{
			game->hero.x += (to_x * 4);
			game->hero.y += (to_y * 4);
			if (++game->hero.step == 7)
				game->hero.step = 1;
			display_game(game);
			steps++;
		}
		apply_changes(game);
	}
	else
		display_game(game);
}

/*
	If the coins is where the player moved
	it decreases its variable.
	if coins is 0 and the player moved to the exit,
	then exits the game successfully.
*/
static void	apply_changes(t_game *game)
{
	int		x;
	int		y;

	x = game->hero.x / 32;
	y = game->hero.y / 32;
	free(game->moves_str);
	game->moves_str = ft_utoa(++game->moves_num);
	if (!BONUS)
		ft_putendl_fd(game->moves_str, 1);
	if (game->map[y][x] == COLL)
	{
		game->coins_num--;
		game->map[y][x] = 0;
	}
	else if (game->map[y][x] == EXIT)
		if (game->door)
			exit_game(game, "YOU WIN !");
}

static void	shoot_arrow(t_game *game)
{
	int		steps;

	game->hero.step = 7;
	steps = game->hero.step;
	while (++steps < 12)
	{
		display_game(game);
		if (steps < 10)
			game->hero.step++;
		else
		{
			if (steps == 10)
				put_arrow(game);
			game->hero.step--;
		}
	}
	game->hero.step = 0;
}
