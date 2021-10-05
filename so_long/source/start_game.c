/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:01 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 21:46:57 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_sprites(t_img **img, void *mlx, char *path);
static void	initialize_structure(t_game *game);
static void	load_environment(t_game *game);

void	start_game(t_game *game)
{
	initialize_structure(game);
	validate_map(game);
	load_environment(game);
	render_game(game);
	move_display(game);
}

/*
** Initializes variables of game structure.
*/
static void	initialize_structure(t_game *game)
{
	game->sprites = (t_sprites *)malloc(sizeof(t_sprites));
	if (!game->sprites)
		error(game, "Malloc for sprites failed\n", errno);
	game->sprites->collectible = 0;
	game->sprites->way_out = 0;
	game->sprites->ground = 0;
	game->sprites->player = 0;
	game->sprites->wall = 0;
	game->moved_nbr = 0;
	game->collects = 0;
	game->exits = 0;
	game->img = 0;
	game->area = 0;
	game->width = 0;
	game->height = 1;
	game->player_p = 0;
}

/*
** Initializes mlx, opens a window and creates an image.
** Exits the game appropriately if any error occurs.
*/
static void	load_environment(t_game *game)
{
	int	x;
	int	y;

	x = game->width * 64;
	y = game->height * 64;
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "Mlx init failed\n", errno);
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	if (!game->win)
		error(game, "Could not create a window\n", errno);
	game->img = mlx_new_image(game->mlx, x, y);
	if (!game->img)
		error(game, "Could not create an image\n", errno);
	load_sprites(&game->sprites->player, game->mlx, "./img/player.xpm");
	load_sprites(&game->sprites->collectible, game->mlx, "./img/collect.xpm");
	load_sprites(&game->sprites->way_out, game->mlx, "./img/exit.xpm");
	load_sprites(&game->sprites->wall, game->mlx, "./img/wall.xpm");
	load_sprites(&game->sprites->ground, game->mlx, "./img/ground.xpm");
	if (!game->sprites->collectible || !game->sprites->ground \
		|| !game->sprites->player || !game->sprites->wall \
		|| !game->sprites->way_out)
		error(game, "Sprites got NULL", errno);
	game->width++;
}

static void	load_sprites(t_img **img, void *mlx, char *path)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	(*img)->height = height;
	(*img)->width = width;
}
