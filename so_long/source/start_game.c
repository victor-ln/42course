/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:01 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 02:32:33 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_sprites(t_sprites *sprites, void *mlx);
static int	char_sprites(t_moves *player, void *mlx, char *path, int len);

void	init_structure(t_game *g)
{
	int		i;

	i = -1;
	ft_bzero(g, 11);
	g->sprites = (t_sprites *)malloc(sizeof(t_sprites));
	if (!g->sprites)
		error(g, "Malloc for sprites failed", strerror(errno));
	ft_bzero(g->sprites, 4);
	g->sprites->hero = (t_moves **)malloc(sizeof(t_moves *) * 4);
	g->sprites->enemy = (t_moves **)malloc(sizeof(t_moves *) * 4);
	g->sprites->coins = (t_img **)malloc(sizeof(t_img *) * 4);
	if (!g->sprites->hero || !g->sprites->enemy || !g->sprites->coins)
		error(g, "Malloc for hero/enemy structs failed", strerror(errno));
	while (++i < 4)
	{
		g->sprites->hero[i] = (t_moves *)malloc(sizeof(t_moves) * 6);
		g->sprites->enemy[i] = (t_moves *)malloc(sizeof(t_moves) * 4);
		if (!g->sprites->hero[i] || !g->sprites->enemy[i, 4])
			error(g, "Malloc for hero/enemy structs failed", strerror(errno));
		g->sprites->hero[i]->walk = (t_img **)malloc(sizeof(t_img *) * 6);
		g->sprites->enemy[i]->walk = (t_img **)malloc(sizeof(t_img *) * 4);
		if (!g->sprites->hero[i]->walk || !g->sprites->enemy[i]->walk)
			error(g, "Malloc for hero/enemy images failed", strerror(errno));
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
	game->win = mlx_new_window(game->mlx, x, y, "so_long");
	if (!game->win)
		error(game, "Could not create a window", strerror(errno));
	game->img = mlx_new_image(game->mlx, x, y);
	if (!game->img)
		error(game, "Could not create an image", strerror(errno));
	if (load_sprites(game->sprites, game->mlx))
		error(game, "Could not load all sprites", 0);
}

static int	load_sprites(t_sprites *s, void *mlx)
{
	int		errors;

	errors = each_sprite(&s->grass, mlx, "sprites/grass");
	errors += each_sprite(&s->tree, mlx, "sprites/tree");
	errors += each_sprite(&s->coins[0], mlx, "sprites/coins/1");
	errors += each_sprite(&s->coins[1], mlx, "sprites/coins/2");
	errors += each_sprite(&s->coins[2], mlx, "sprites/coins/3");
	errors += each_sprite(&s->coins[3], mlx, "sprites/coins/4");
	errors += each_sprite(&s->door_o, mlx, "sprites/door/opened");
	errors += each_sprite(&s->door_c, mlx, "sprites/door/closed");
	errors += char_sprites(&s->hero[RIGHT], mlx, "sprites/hero/right/ ", 6);
	errors += char_sprites(&s->enemy[RIGHT], mlx, "sprites/enemy/right/ ", 4);
	errors += char_sprites(&s->hero[LEFT], mlx, "sprites/hero/left/ ", 6);
	errors += char_sprites(&s->enemy[LEFT], mlx, "sprites/enemy/left/ ", 4);
	errors += char_sprites(&s->hero[DOWN], mlx, "sprites/hero/down/ ", 6);
	errors += char_sprites(&s->enemy[DOWN], mlx, "sprites/enemy/down/ ", 4);
	errors += char_sprites(&s->hero[UP], mlx, "sprites/hero/up/ ", 6);
	errors += char_sprites(&s->enemy[UP], mlx, "sprites/enemy/up/ ", 4);
	return (errors);
}

static int	char_sprites(t_moves *player, void *mlx, char *path, int len)
{
	char	*temp;
	size_t	len;
	int		errors;
	int		i;

	i = 0;
	temp = ft_strdup(path);
	len = ft_strlen(temp) - 5;
	temp[len] = '0';
	errors = each_sprite(&player->idle, mlx, temp);
	while (i < len)
	{
		temp[len] = i + '1';
		errors += each_sprite(&player->walk[i], mlx, temp);
		i++;
	}
	free(temp);
	return (errors);
}

int	each_sprite(t_img **img, void *mlx, char *path)
{
	int		height;
	int		width;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (*img)
	{
		(*img)->height = height;
		(*img)->width = width;
		return (0);
	}
	return (1);
}
