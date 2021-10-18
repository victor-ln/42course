/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:33:23 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 17:51:30 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_sprites(t_sprites *sprites, void *mlx);
static int	a_sprite(t_img *image, void *mlx, char *path);
static int	a_set(t_img **ptr, void *mlx, char *path, int size);

void	struct_init(t_game *game)
{
	int		i;

	i = 0;
	ft_bzero(game, 15);
	game->height = 1;
	game->sprites.enemy = (t_img ***)malloc(sizeof(t_img **) * 4);
	game->sprites.hero = (t_img ***)malloc(sizeof(t_img **) * 4);
	game->sprites.coins = (t_img **)malloc(sizeof(t_img *) * 4);
	game->sprites.door = (t_img **)malloc(sizeof(t_img *) * 2);
	if (!game->sprites.hero || !game->sprites.enemy || \
		!game->sprites.coins || !game->sprites.door)
		error(game, "Malloc to images ptrs failed", strerror(errno));
	while (i < 4)
	{
		game->sprites.hero[i] = (t_img **)malloc(sizeof(t_img *) * 6);
		game->sprites.enemy[i] = (t_img **)malloc(sizeof(t_img *) * 4);
		if (game->sprites.enemy[i] || game->sprites.hero[i])
			error(game, "Malloc to image ptrs failed", strerror(errno));
		i++;
	}
}

void	load_environment(t_game *game)
{
	int		x;
	int		y;

	x = game->width * 32;
	y = game->height * 32;
	game->mlx = mlx_init();
	if (!game->mlx)
		error(game, "Mlx init failed", strerror(errno));
	game->screen = mlx_new_window(game->mlx, x, y, "so_long");
	if (!game->screen)
		error(game, "Could not create a window", strerror(errno));
	game->img = mlx_new_image(game->mlx, x, y);
	if (!game->img)
		error(game, "Could not create images", strerror(errno));
	if (load_sprites(&game->sprites, game->mlx))
		error(game, "Could not load all sprites", 0);
	game->moves_str = ft_utoa(0);
}

static int	load_sprites(t_sprites *s, void *mlx)
{
	int		error;

	error = a_sprite(s->grass, mlx, "img/env/grass.xpm");
	error += a_sprite(s->tree, mlx, "img/env/tree.xpm");
	error += a_set(s->door, mlx, ft_strdup("img/env/door- .xpm"), 2);
	error += a_set(s->coins, mlx, ft_strdup("img/coins/coin- .xpm"), 4);
	error += a_set(s->hero[RIGHT], mlx, ft_strdup("img/hero/right/ .xpm"), 7);
	error += a_set(s->hero[LEFT], mlx, ft_strdup("img/hero/left/ .xpm"), 7);
	error += a_set(s->hero[DOWN], mlx, ft_strdup("img/hero/down/ .xpm"), 7);
	error += a_set(s->hero[UP], mlx, ft_strdup("img/hero/up/ .xpm"), 7);
	error += a_set(s->enemy[RIGHT], mlx, ft_strdup("img/enemy/right/ .xpm"), 5);
	error += a_set(s->enemy[LEFT], mlx, ft_strdup("img/enemy/left/ .xpm"), 5);
	error += a_set(s->enemy[DOWN], mlx, ft_strdup("img/enemy/down/ .xpm"), 5);
	error += a_set(s->enemy[UP], mlx, ft_strdup("img/enemy/up/ .xpm"), 5);
	return (error);
}

static int	a_set(t_img **ptr, void *mlx, char *path, int size)
{
	int		errors;
	int		num;
	int		i;

	i = 0;
	errors = 0;
	num = ft_strlen(path) - 5;
	while (i < size)
	{
		path[num] = '0' + i;
		errors += a_sprite(ptr[i], mlx, path);
		i++;
	}
	free(path);
	return (errors);
}

/*
	Loads a xpm file located in path to the image address pointer passed.
*/
static int	a_sprite(t_img *image, void *mlx, char *path)
{
	int		height;
	int		width;

	image = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (image != NULL)
	{
		image->height = height;
		image->width = width;
		return (0);
	}
	return (1);
}
