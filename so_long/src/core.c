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

/*
** The core, initializes the structure, starts the game,
** hooks keys pressed and window events and renders.
*/
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

/*
** Controls where to move when keycode is "asdw" or
** exit_game if ESC is pressed.
*/
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

/*
** Exit_game if close_window box is clicked.
*/
static int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	exit_game("Window closed\n", EXIT_SUCCESS, game);
	return (0);
}

/*
** Receives the direction to move.
** If direction is not valid it does nothing, else renders
** the ground img in the player position and the player in the direction.
** Checks if collects is in direction and decrements collects variable.
** If collects is 0 and direction points to exit, then exit_game successfully.
*/
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

	actual_line = player_p / line_len = 1
	actual_col = (line_len = 6 - (player_p % line_len = 3)) = 3
	(player_p += direction) = 15
	next_line = (player_p = 15 / line_len = 6) = 2;
	next_col = (line_len = 6 - (player_p = 15 % line_len = 6) = 3) = 3;
*/

/*
** Receives direction and calculates the colum and line to move the player,
** draws the sprite of the ground in the actual position, the player in the moved
** and puts the string with the number of movements done.
*/
static void	update(t_game *game, int direction)
{
	int		actual_line;
	int		actual_col;
	int		next_line;
	int		next_col;
	char	*temp;

	temp = ft_utoa(game->moved_nbr);
	if (!temp)
		exit_game("Malloc error\n", EXIT_FAILURE, game);
	actual_line = game->map.player_p / game->map.width;
	actual_col = game->map.width - (game->map.player_p % game->map.width);
	game->map.player_p += direction;
	next_line = game->map.player_p / game->map.width;
	next_col = game->map.width - (game->map.player_p % game->map.width);
	draw_img(game->image, game->sprites.ground, actual_col, actual_line);
	draw_img(game->image, game->sprites.player, next_col, next_line);
	mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0, "Moved : ");
	mlx_string_put(game->mlx, game->win, 8, 0, 0x0, temp);
	free(temp);
	temp = 0;
}
