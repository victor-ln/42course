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
static void	render_movement(t_game *game, int direction);
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
	game->moved_nbr++;
	render_movement(game, direction);
}

static void	render_movement(t_game *game, int direction)
{
	int	actual_col;
	int	after_col;
	int	actual_line;
	int	after_line;
	int	line_len;

	game->moved_str = ft_utoa(game->moved_nbr);
	line_len = (game->map.area / game->map.height + 1);
	actual_line = game->map.player_p / line_len;
	actual_col = (line_len - 1) - (game->map.player_p
			% (game->map.area / game->map.height));
	game->map.player_p += direction;
	after_line = (game->map.player_p + direction) / line_len;
	after_col = (line_len - 1) - ((game->map.player_p + direction)
			% (game->map.area / game->map.height));
	draw_img(game->sprites.ground, actual_col, actual_line);
	draw_img(game->sprites.player, after_col, after_line);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0, "Moved : ");
	mlx_string_put(game->mlx, game->win, 8, 0, 0x0, game->moved_str);
	free(game->moved_str);
	game->moved_str = 0;
}
