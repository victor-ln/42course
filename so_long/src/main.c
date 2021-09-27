/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:14:27 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/24 00:14:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move(t_game *game, int direction);
static int	key_pressed(int keycode, t_game *game);
static int	close_window(int keycode, t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		exit_game("Invalid number of arguments\n", EXIT_FAILURE, 0);
	init_structs(&game);
	game.map.map = load_map(argv[1]);
	start_game(&game);
	mlx_key_hook(game.win, key_pressed, &game);
	mlx_hook(game.win, 17, 0L, close_window, &game);
	mlx_loop(game.mlx);
}

static int	key_pressed(int keycode, t_game *game)
{
	if (keycode == 'd')
		move(game, 1);
	else if (keycode == 'a')
		move(game, -1);
	else if (keycode == 's')
		move(game, (game->map.area / game->map.height +  1));
	else if (keycode == 'w')
		move(game, ((game->map.area / game->map.height + 1) * -1));
	else if (keycode == ESC)
		exit_game("ESC pressed\n", EXIT_SUCCESS, game);
	return (0);
}

static int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	return (exit_game("Window closed\n", EXIT_SUCCESS, game));
}

static void	move(t_game *game, int direction)
{
	if (game->map.map[game->map.player_p + direction] == '1')
		return ;
	if (game->map.map[game->map.player_p + direction] == 'C')
		game->map.collects--;
	else if (game->map.map[game->map.player_p + direction] == 'E')
		if (!game->map.collects)
			exit_game("YOU WIN !\n", EXIT_SUCCESS, game);
	game->map.map[game->map.player_p] = '0';
	game->map.map[game->map.player_p + direction] = 'P';
	game->map.player_p += direction;
	game->moved_nbr++;
	render(game);
}
