/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:01 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/01 03:43:22 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	each_one(t_img **img, void *mlx, char *path);
static void	initialize_structure(t_game *game);
static void	load_environment(t_game *game);
static void	load_sprites(t_game *game);

void	start_game(t_game *game)
{
	initialize_structure(game);
	validate_map(game);
	load_environment(game);
	load_sprites(game);
	render_game(game);
}

/*
** Initializes variables of game structure.
*/
static void	initialize_structure(t_game *game)
{
	game->image = 0;
	game->sprites.collectible = 0;
	game->sprites.way_out = 0;
	game->sprites.ground = 0;
	game->sprites.player = 0;
	game->sprites.wall = 0;
	game->collects = 0;
	game->exits = 0;
	game->area = 0;
	game->height = 1;
	game->width = 0;
	game->player_p = 0;
	game->mlx = 0;
	game->win = 0;
}

/*
** Initializes mlx, opens a window and creates an image.
** Exits the game appropriately if any error occurs.
*/
static void	load_environment(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "Mlx_init failed", 2);
	x = game->width * 32;
	y = game->height * 32;
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	game->image = mlx_new_image(game->mlx, x, y);
	if (!game->win)
		exit_game(game, "Could not create a window", 2);
	if (!game->image)
		exit_game(game, "Could not create an image", 2);
}

/*
** Saves the sprites from ./images dir in their struct pointers.
*/
static void	load_sprites(t_game *game)
{
	each_one(&game->sprites.player, game->mlx, "./img/player.xpm");
	each_one(&game->sprites.collectible, game->mlx, "./img/collect.xpm");
	each_one(&game->sprites.way_out, game->mlx, "./img/exit.xpm");
	each_one(&game->sprites.wall, game->mlx, "./img/wall.xpm");
	each_one(&game->sprites.ground, game->mlx, "./img/ground.xpm");
	if (!game->sprites.collectible || !game->sprites.way_out \
	|| !game->sprites.ground || !game->sprites.player || !game->sprites.wall)
		exit_game(game, "Sprites got NULL", 2);
}

static void	each_one(t_img **img, void *mlx, char *path)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	(*img)->height = height;
	(*img)->width = width;
}
