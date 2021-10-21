/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:41:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/21 12:23:08 by vlima-nu         ###   ########.fr       */
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
	if (keycode == ESC)
		exit_game(game, "ESC pressed.");
	if (keycode == 'd')
		move_player(game, RIGHT, 1, 0);
	else if (keycode == 'a')
		move_player(game, LEFT, -1, 0);
	else if (keycode == 's')
		move_player(game, DOWN, 0, 1);
	else if (keycode == 'w')
		move_player(game, UP, 0, -1);
	return (0);
}

static void	move_player(t_game *game, short dir, int to_x, int to_y)
{
	int		x;
	int		y;
	int		steps;

	x = game->hero.x / 32;
	y = game->hero.y / 32;
	game->hero.dir = dir;
	display_game(game);
	if (game->map[y + to_y][x + to_x] == 1)
		return ;
	if (game->map[y][x] != EXIT)
		game->map[y][x] = 0;
	steps = 0;
	while (steps <= 7)
	{
		game->hero.x += (to_x * 4);
		game->hero.y += (to_y * 4);
		if (++game->hero.step == 7)
			game->hero.step = 1;
		move_enemies(game);
		display_game(game);
		steps++;
	}
	apply_changes(game);
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
	if (game->map[y][x] == COLL)
		game->coins_num--;
	if (game->map[y][x] == EXIT)
	{
		if (!game->coins_num)
			exit_game(game, "YOU WIN !");
	}
	else
		game->map[y][x] = HERO;
	game->hero.step = 0;
}

void	hero_got_caught(t_game *game)
{
	int		i;

	i = 0;
	if (!BONUS)
		return ;
	while (i < game->enemies_num)
	{
		if (game->hero.x == game->enemies[i].x && \
			game->hero.y == game->enemies[i].y)
			exit_game(game, "YOU LOSE.");
		i++;
	}
}
