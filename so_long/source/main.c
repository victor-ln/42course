/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:42 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:44:58 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		start_game(t_game *game);

/*
	The core, starts the game, hooks the keys pressed,
	closes the window and keeps display in looping.
*/
int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(0, "Malloc to game struct failed", strerror(errno));
	load_map(game, check_input(argc, argv[argc - 1]));
	start_game(game);
	mlx_key_hook(game->screen, key_press, game);
	mlx_hook(game->screen, 17, 0L, close_window, game);
	mlx_loop_hook(game->display, animation, game);
	mlx_loop(game->display);
}

/*
	Calls the key functions of the game.
*/
static void	start_game(t_game *game)
{
	struct_init(game);
	map_init(game);
	load_environment(game);
	draw_game(game);
}
