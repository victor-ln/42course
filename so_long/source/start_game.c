/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:01 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:58:08 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_sprites(t_sprites *sprites, void *display);
static int	characters(t_moves *character, void *display, char *path, int size);

void	struct_init(t_game *game)
{
	int		i;

	i = 0;
	ft_bzero(game, 12);
	ft_bzero(&game->sprites, 4);
	game->height = 1;
	game->sprites.hero = (t_moves **)malloc(sizeof(t_moves *) * 4);
	game->sprites.enemy = (t_moves **)malloc(sizeof(t_moves *) * 4);
	game->sprites.coins = (t_img **)malloc(sizeof(t_img *) * 4);
	game->coins_img = (t_img **)malloc(sizeof(t_img *) * 4);
	if (!game->sprites.hero || !game->sprites.enemy || !game->sprites.coins)
		error(game, "Malloc to hero/enemy structs failed", strerror(errno));
	while (i < 4)
	{
		game->sprites.hero[i] = (t_moves *)malloc(sizeof(t_moves));
		game->sprites.enemy[i] = (t_moves *)malloc(sizeof(t_moves));
		if (!game->sprites.hero[i] || !game->sprites.enemy[i])
			error(game, "Malloc to t_moves struct failed", strerror(errno));
		game->sprites.hero[i]->walk = (t_img **)malloc(sizeof(t_img *) * 6);
		game->sprites.enemy[i]->walk = (t_img **)malloc(sizeof(t_img *) * 4);
		if (!game->sprites.hero[i]->walk || !game->sprites.enemy[i]->walk)
			error(game, "Malloc to ptr of images ptrs failed", strerror(errno));
		i++;
	}
}

void	load_environment(t_game *game)
{
	int		x;
	int		y;

	x = game->width * 32;
	y = game->height * 32;
	game->display = mlx_init();
	if (!game->display)
		error(game, "Mlx init failed", strerror(errno));
	game->screen = mlx_new_window(game->display, x, y, "so_long");
	if (!game->screen)
		error(game, "Could not create a window", strerror(errno));
	game->map_img = mlx_new_image(game->display, x, y);
	game->coins_img[0] = mlx_new_image(game->display, x, y);
	game->coins_img[1] = mlx_new_image(game->display, x, y);
	game->coins_img[2] = mlx_new_image(game->display, x, y);
	game->coins_img[3] = mlx_new_image(game->display, x, y);
	if (!game->map_img || !game->coins_img[0] || !game->coins_img[1] \
		|| !game->coins_img[2] || !game->coins_img[3])
		error(game, "Could not create images", strerror(errno));
	if (load_sprites(&game->sprites, game->display))
		error(game, "Could not load all sprites", 0);
}

static int	load_sprites(t_sprites *s, void *display)
{
	int		errors;

	errors = each_sprite(&s->grass, display, "sprites/env/grass.xpm");
	errors += each_sprite(&s->tree, display, "sprites/env/tree.xpm");
	errors += each_sprite(&s->coins[0], display, "sprites/coins/coin-1.xpm");
	errors += each_sprite(&s->coins[1], display, "sprites/coins/coin-2.xpm");
	errors += each_sprite(&s->coins[2], display, "sprites/coins/coin-3.xpm");
	errors += each_sprite(&s->coins[3], display, "sprites/coins/coin-4.xpm");
	errors += each_sprite(&s->door_o, display, "sprites/env/door_o.xpm");
	errors += each_sprite(&s->door_c, display, "sprites/env/door_c.xpm");
	errors += characters(s->hero[RIGHT], display, "sprites/hero/right/ .xpm", 6);
	errors += characters(s->hero[LEFT], display, "sprites/hero/left/ .xpm", 6);
	errors += characters(s->hero[DOWN], display, "sprites/hero/down/ .xpm", 6);
	errors += characters(s->hero[UP], display, "sprites/hero/up/ .xpm", 6);
	errors += characters(s->enemy[RIGHT], display, "sprites/enemy/right/ .xpm", 4);
	errors += characters(s->enemy[LEFT], display, "sprites/enemy/left/ .xpm", 4);
	errors += characters(s->enemy[DOWN], display, "sprites/enemy/down/ .xpm", 4);
	errors += characters(s->enemy[UP], display, "sprites/enemy/up/ .xpm", 4);
	return (errors);
}

static int	characters(t_moves *character, void *display, char *path, int size)
{
	char	*temp;
	size_t	length;
	int		errors;
	int		i;

	i = 0;
	temp = ft_strdup(path);
	length = ft_strlen(temp) - 5;
	temp[length] = '0';
	errors = each_sprite(&character->idle, display, temp);
	while (i < size)
	{
		temp[length] = i + '1';
		errors += each_sprite(&character->walk[i], display, temp);
		i++;
	}
	free(temp);
	return (errors);
}

int	each_sprite(t_img **image, void *display, char *path)
{
	int		height;
	int		width;

	*image = mlx_xpm_file_to_image(display, path, &width, &height);
	if (*image)
	{
		(*image)->height = height;
		(*image)->width = width;
		return (0);
	}
	return (1);
}
