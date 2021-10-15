/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:41:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:54:14 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_hero(t_game *game, int direction, int to_x, int to_y);
static void	apply_changes(t_game *game);
static void	take_coins(t_game *game);

int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	exit_game(game, "Window closed\n");
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 'd')
		move_hero(game, RIGHT, 4, 0);
	else if (keycode == 'a')
		move_hero(game, LEFT, -4, 0);
	else if (keycode == 'w')
		move_hero(game, UP, 0, -4);
	else if (keycode == 's')
		move_hero(game, DOWN, 0, 4);
	else if (keycode == ESC)
		exit_game(game, "ESC pressed\n");
	return (0);
}

static void	move_hero(t_game *game, int direction, int to_x, int to_y)
{
	int		steps;
	int		x;
	int		y;

	steps = 0;
	x = game->hero.x / 32;
	y = game->hero.y / 32;
	game->moved_to = direction;
	display_game(game, -1);
	if ((game->map[y + (to_y / 4)][x + (to_x / 4)] == EXIT && game->coins_n)
		|| game->map[y + (to_y / 4)][x + (to_x / 4)] == 1)
		return ;
	game->map[y][x] = 0;
	while (steps <= 7)
	{
		game->hero.x += to_x;
		game->hero.y += to_x;
		if (steps < 7)
			display_game(game, steps++);
	}
	apply_changes(game);
}

/*
	If the player position is the same that the enemy one the game is over.
	If the coins is where the player moved
	decreases its variable and draws the ground instead the coins.
	Draws the exit door opened if coins is 0.
	Also if coins is 0 and the player moved to the exit,
	then exits the game successfully.
	Finally displays the player in the moved position and the number of movements.
*/
static void	apply_changes(t_game *game)
{
	int		x;
	int		y;

	x = game->hero.x / 32;
	y = game->hero.y / 32;
	free(game->moves_str);
	game->moves_str = ft_utoa(++game->moves);
	display_game(game, -1);
	if (game->map[y][x] == COLL)
		take_coins(game);
	game->map[y][x] = 0;
	if (game->map[y][x] == EXIT)
		if (!game->coins_n)
			exit_game(game, "YOU WIN !\n");
}

static void	take_coins(t_game *game)
{
	int		i;

	i = 0;
	while (game->coins[i].x != game->hero.x && \
			game->coins[i].y != game->hero.y)
		i++;
	erase_coins(game->coins_img, game->coins[i].x, game->coins[i].y);
	game->coins_n--;
	if (!game->coins_n)
		draw_sprite(game->map_img, game->sprites.door_o, \
				game->exit.x, game->exit.y);
}
