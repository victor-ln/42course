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
	return (exit_game("Window closed\n", EXIT_SUCCESS, game));
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
	width = (20 / 4 + 1) = 6

	actual_line = ((player_p) / width) = 1
	actual_col = width - ((player_p % width) = 3) = 3
	after_line = ((player_p = 9 + direction = 6) / width = 6) = 2;
	after_col = (width - (player_p = 9 + direction = 6) % width = 3) = 3;
*/

static void	update(t_game *game, int direction)
{
	int		col;
	int		line;
	char	*temp;

	temp = ft_utoa(game->moved_nbr);
	line = game->map.player_p / game->map.width;
	col = game->map.width - (game->map.player_p % game->map.width);
	game->map.player_p += direction;
	if (direction > 1 || direction < -1)
		draw_img(game->image, game->sprites.player,
			(game->map.player_p / game->map.width), col);
	else
		draw_img(game->image, game->sprites.player, line,
			(game->map.width - (game->map.player_p % game->map.width)));
	mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0, "Moved : ");
	mlx_string_put(game->mlx, game->win, 8, 0, 0x0, temp);
	free(temp);
	temp = 0;
}
