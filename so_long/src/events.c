/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:41:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/25 10:44:52 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	apply_changes(t_game *game);
static void	move_player(t_game *game, short dir, int to_x, int to_y);

int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	ft_putendl_fd("Window closed.", 1);
	exit(0);
}

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
	else if (keycode == ESC)
		exit_game(game, "ESC pressed.");
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	(void)keycode;
	game->hero.step = 0;
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
			if (++game->hero.step % 7 == 0)
				game->hero.step++;
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
		if (--game->coins_num == 0)
			game->door = 1;
		game->map[y][x] = 0;
	}
	else if (game->map[y][x] == EXIT)
		if (!game->coins_num)
			exit_game(game, "YOU WIN !");
}
