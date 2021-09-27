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
static void	update(t_game *game, int direction);
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
		move(game, (game->map.area / game->map.height + 1));
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
	if (game->map.map[game->map.player_p + direction] == '1'
		|| game->map.map[game->map.player_p + direction] == '\n')
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
	update(game, direction);
}

static void	update(t_game *game, int direction)
{
	int	player_col;
	int	player_line;
	int	direction_col;
	int	direction_line;
	int	line_len;

	game->moved_str = ft_utoa(game->moved_nbr);
	line_len = (game->map.area / game->map.height + 1);
	player_line = game->map.player_p / line_len;
	direction_line = (game->map.player_p + direction) / line_len;
	line_len--;
	player_col = line_len - game->map.player_p % (game->map.area / game->map.height);
	direction_col = line_len - (game->map.player_p + direction) % (game->map.area / game->map.height);
	draw_img(game->sprites.player, player_col, player_line);
	draw_img(game->sprites.ground, direction_col, direction_line);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0, "Moved : ");
	mlx_string_put(game->mlx, game->win, 8, 0, 0x0, game->moved_str);
	free(game->moved_str);
	game->moved_str = 0;
}

/*

	1	1	1	1	1	\n
	1	0	0	P	1	\n
	1	C	1	0	1	\n
	1	0	1	C	1	\n
	1	E	1	1	1	\n
	1	1	1	1	1	\0

*/
