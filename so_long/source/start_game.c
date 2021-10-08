/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:01 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 21:17:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_structure(t_game *g)
{
	ft_bzero(g, 12);
	g->sprites = (t_sprites *)malloc(sizeof(t_sprites));
	if (!g->sprites)
		error(g, "Malloc for sprites failed\n", strerror(errno));
	ft_bzero(g->sprites, 4);
	g->sprites->player_d = (t_player **)
		malloc_matrix((sizeof(t_img *) * 3), sizeof(t_player *) * 4);
	if (!g->sprites->player_d)
		error(g, "Malloc for player structure failed\n", strerror(errno));
}

void	load_environment(t_game *game)
{
	int	x;
	int	y;

	x = game->width * 64;
	y = game->height * 64;
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "Mlx init failed\n", strerror(errno));
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	if (!game->win)
		error(game, "Could not create a window\n", strerror(errno));
	game->img = mlx_new_image(game->mlx, x, y);
	if (!game->img)
		error(game, "Could not create an image\n", strerror(errno));
	load_sprite(&game->sprites->ground, game->mlx, "./sprites/ground");
	load_sprite(&game->sprites->wall, game->mlx, "./sprites/wall");
	load_sprite(&game->sprites->collect, game->mlx, "./sprites/collect");
	load_sprite(&game->sprites->way_out, game->mlx, "./sprites/exit/0");
}

void	load_sprite(t_img **img, void *mlx, char *path)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	(*img)->height = height;
	(*img)->width = width;
}
