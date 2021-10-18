/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:42 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 14:15:52 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_game(t_game *game, int fd);
static void	start_game(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(0, "Malloc to game struct failed", strerror(errno));
	load_game(game, check_input(argc, argv[argc - 1]));
	start_game(game);
}

static void	load_game(t_game *game, int fd)
{
	struct_init(game);
	load_map(game, fd);
	map_init(game);
	load_environment(game);
	display_game(game);
}

static void	start_game(t_game *game)
{
	mlx_hook(game->screen, 2, 1L << 0, key_press, game);
	mlx_hook(game->screen, 17, 0L, close_window, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}
