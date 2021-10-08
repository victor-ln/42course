/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:42 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 18:24:36 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	start_game(t_game *game, int fd);

/*
** The core, starts the game, hooks the keys pressed,
** closes the window and keeps display in looping.
*/
int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(0, "Malloc failed for game struct", strerror(errno));
	start_game(game, check_input(argc, argv[argc - 1]));
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop(game->mlx);
}

/*
** Calls the key functions of the game.
*/
static	void	start_game(t_game *game, int fd)
{
	initialize_structure(game);
	load_map(game, fd);
	map_init(game);
	load_environment(game);
	render_game(game);
}
