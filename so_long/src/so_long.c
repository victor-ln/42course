/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 19:18:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/22 00:14:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		load_game(t_game *game, int fd);
static void		game_init(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	load_game(game, check_input(argc, argv[argc - 1]));
	mlx_hook(game->screen, 17, 0L, close_window, game);
	mlx_key_hook(game->screen, key_press, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}

static void	load_game(t_game *game, int fd)
{
	game_init(game);
	load_map(game, fd);
	map_init(game);
	load_environment(game);
	display_game(game);
}

static void	game_init(t_game *game)
{
	if (!game)
		error(0, "Malloc for game struct failed", strerror(errno));
	game->sprites.coins = 0;
	game->sprites.hero = 0;
	game->sprites.enemy = 0;
	game->sprites.door = 0;
	game->sprites.tree = 0;
	game->sprites.grass = 0;
	game->coins_num = 0;
	game->enemies = 0;
	game->frame = 0;
	game->img = 0;
	game->mlx = 0;
	game->screen = 0;
	game->map = 0;
	game->map_ber = 0;
	game->moves_num = 0;
	game->moves_str = 0;
	game->enemies_num = 0;
}
