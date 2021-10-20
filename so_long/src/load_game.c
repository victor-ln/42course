/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:47:10 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/20 00:04:23 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_init(t_game *game);

void	load_game(t_game *game, int fd)
{
	game_init(game);
	load_map(game, fd);
	map_init(game);
	load_environment(game);
	display_game(game);
}

void	display_game(t_game *game)
{
	draw_game(game);
	mlx_put_image_to_window(game->mlx, game->screen, game->img, 0, 0);
	mlx_string_put(game->mlx, game->screen, 10, 10, C_WHITE, "Moved :");
	mlx_string_put(game->mlx, game->screen, 60, 10, C_WHITE, game->moves_str);
}

static void	game_init(t_game *game)
{
	if (!game)
		error(0, "Malloc for game struct failed", strerror(errno));
	game->sprites.coins = 0;
	game->sprites.hero = 0;
	game->sprites.door = 0;
	game->sprites.enemy = 0;
	game->sprites.grass = 0;
	game->sprites.tree = 0;
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
}
