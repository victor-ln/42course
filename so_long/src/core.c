/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:51:32 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/27 23:51:32 by vlima-nu         ###   ########.fr       */
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
		exit_game("Invalid number of arguments\n", EXIT_FAILURE, &game);
	init_struct(&game);
	game.map.content = load_map(argv[1]);
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
		move(game, game->map.width);
	else if (keycode == 'w')
		move(game, (game->map.width * -1));
	else if (keycode == ESC)
		exit_game("ESC pressed\n", EXIT_SUCCESS, game);
	return (0);
}

static int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	exit_game("Window closed\n", EXIT_SUCCESS, game);
	return (0);
}

static void	move(t_game *game, int direction)
{
	if (game->map.content[game->map.player_p + direction] == '1')
		return ;
	game->moved_nbr++;
	if (game->map.content[game->map.player_p + direction] == 'C')
		game->map.collects--;
	else if (game->map.content[game->map.player_p + direction] == 'E')
		if (!game->map.collects)
			exit_game("YOU WIN !\n", EXIT_SUCCESS, game);
	update(game, direction);
}

/*
	Map example:

	0	1	2	3	4	5	columns

	1	1	1	1	1	\n	line 0
	1	0	C	P	1	\n	line 1
	1	E	1	C	1	\n	line 2
	1	1	1	1	1	\0	line 3

	Move example:

	if (keycode = 's')
		direction = ((area = 20) / (height = 4) + 1) = 6
	player_position = 9
	line_len = (20 / 4 + 1) = 6

	actual_line = ((player_p) / line_len) = 1
	actual_col = line_len - ((player_p % line_len) = 3) = 3
	after_line = ((player_p = 9 + direction = 6) / line_len = 6) = 2;
	after_col = (line_len - (player_p = 9 + direction = 6) % line_len = 3) = 3;
*/

static void	update(t_game *game, int direction)
{
	int		actual_col;
	int		after_col;
	int		actual_line;
	int		after_line;
	char	*temp;

	temp = ft_utoa(game->moved_nbr);
	if (!temp)
		exit_game("Malloc error\n", EXIT_FAILURE, game);
	actual_line = game->map.player_p / game->map.width;
	actual_col = game->map.width - (game->map.player_p % game->map.width);
	game->map.player_p += direction;
	after_line = game->map.player_p / game->map.width;
	after_col = game->map.width - (game->map.player_p % game->map.width);
	draw_img(game->image, game->sprites.ground, actual_col, actual_line);
	draw_img(game->image, game->sprites.player, after_col, after_line);
	mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0, "Moved : ");
	mlx_string_put(game->mlx, game->win, 8, 0, 0x0, temp);
	free(temp);
	temp = 0;
}
