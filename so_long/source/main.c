/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:42 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 21:56:46 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
** The core of the game, loads the map, starts the game,
** hooks the keys pressed, closes the window and keeps display in looping.
*/
int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(0, "Malloc for game failed\n", errno);
	load_map(game, argc, argv[argc - 1]);
	start_game(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}
