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

static void	move(t_game *s_game, int direction);
static int	key_pressed(int keycode, t_game *s_game);
static int	close_window(int keycode, t_game *s_game);

int	main(int argc, char *argv[])
{
	t_game	s_game;

	if (argc != 2)
		exit_game("Invalid number of arguments\n", EXIT_FAILURE, 0);
	s_game.map.map = load_map(argv[1]);
	start_game(&s_game);
	mlx_key_hook(s_game.win, key_pressed, &s_game);
	mlx_hook(s_game.win, 17, 0L, close_window, &s_game);
	mlx_loop(s_game.mlx);
}

static int	key_pressed(int keycode, t_game *s_game)
{
	if (keycode == 'd')
		move(s_game, 1);
	if (keycode == 'a')
		move(s_game, -1);
	if (keycode == 's')
		move(s_game, (s_game->map.x / s_game->map.y));
	if (keycode == 'w')
		move(s_game, ((s_game->map.x / s_game->map.y) * -1));
	if (keycode == ESC)
		exit_game("ESC pressed\n", EXIT_SUCCESS, s_game);
	return (0);
}

static int	close_window(int keycode, t_game *s_game)
{
	(void)keycode;
	return (exit_game("Window closed\n", EXIT_SUCCESS, s_game));
}

static void	move(t_game *s_game, int direction)
{
	if (direction <= 0 || direction >= s_game->map.x)
		return ;
	if (s_game->map.map[s_game->map.player_p + direction] != '1')
	{
		if (s_game->map.map[s_game->map.player_p + direction] == 'C')
			s_game->map.collects--;
		else if (s_game->map.map[s_game->map.player_p + direction] == 'E')
			if (!s_game->map.collects)
				exit_game("YOU WIN !\n", EXIT_SUCCESS, s_game);
		s_game->map.map[s_game->map.player_p] = '0';
		s_game->map.map[s_game->map.player_p + direction] = 'P';
		s_game->map.player_p += direction;
		s_game->moved_nbr++;
		render(s_game);
	}
}
