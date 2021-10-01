/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:38:42 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/01 04:03:54 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(int direction, t_game *game);

int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	exit_game(game, "Window closed\n", 1);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 'd')
		move(1, game);
	else if (keycode == 'a')
		move(-1, game);
	else if (keycode == 's')
		move(game->width, game);
	else if (keycode == 'w')
		move((game->width * -1), game);
	else if (keycode == ESC)
		exit_game(game, "ESC pressed\n", 1);
	return (0);
}

/*
** Receives the direction to move.
** If the direction points to a wall,
** it does nothing but renders the game later
** to change player position value to "0" and
** direction plus player position value to "P" on the map.
** Checks if the collects is in the direction and
** decreases its variable if it is.
** If the collection is 0 and the direction points to the exit,
** then exits the game successfully.
*/
static void	move(int direction, t_game *game)
{
	if (game->map[game->player_p + direction] == '1')
		return ;
	if (game->map[game->player_p + direction] == 'C')
		game->collects--;
	else if (game->map[game->player_p + direction] == 'E')
		if (!game->collects)
			exit_game(game, "YOU WIN !\n", 1);
	game->map[game->player_p] = '0';
	game->map[game->player_p + direction] = 'P';
	render_game(game);
}
