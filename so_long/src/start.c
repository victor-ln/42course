/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:14:07 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/24 00:14:07 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	init_map(t_map map, char *ptr);
static void	get_sprites(t_sprites *s, void *mlx);
static void	specific_one(t_img *img, void *mlx, char *path);
static void	check_errors(t_game *game, int status);

void	start_game(t_game *game)
{
	check_errors(game, init_map(game->map, game->map.map));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game("Mlx_init got NULL\n", EXIT_FAILURE, game);
	game->win = mlx_new_window(game->mlx, game->map.x * 64,
			game->map.y * 64, "so_long");
	if (!game->win)
		exit_game("Couldn't create a window\n", EXIT_FAILURE, game);
	get_sprites(&game->sprites, game->mlx);
	if (!game->sprites.collect || !game->sprites.exit || !game->sprites.ground
		|| !game->sprites.player || !game->sprites.wall)
		exit_game("Sprites got NULL\n", EXIT_FAILURE, game);
	render(game);
}

static void	check_errors(t_game *game, int status)
{
	if (status == 1)
		exit_game("Invalid map, it's a square\n", 1, game);
	if (status == 2)
		exit_game("Invalid map, unknown char or map not surrounded by walls\n",
			1, game);
	if (status == 4 || game->map.x % game->map.y)
		exit_game("Invalid map, it's not rectangular\n", 1, game);
	if (game->map.y < 3)
		exit_game("Invalid map, not enough lines or columns\n", 1, game);
	game->map.map += game->map.x - (game->map.x / game->map.y);
	while (*game->map.map == '1')
		game->map.map++;
	if (status == 3 || *game->map.map)
		exit_game("Invalid map, it's not surrounded by walls\n", 1, game);
	if (game->map.exit != 1 || game->map.player != 1 || !game->map.collects)
		exit_game("Invalid map, it needs an exit, a player and collects\n",
			1, game);
	write(1, "Valid map\n", 9);
}

static int	init_map(t_map map, char *ptr)
{
	while ((strchr(MAP, *ptr) && map.y) || (!map.y && *ptr == '1'))
	{
		if (*ptr != '\n')
			map.x++;
		else if (*(ptr + 1) != '1' || *(ptr - 1) != '1')
			return (3);
		else if (map.x % map.y)
			return (4);
		else
			map.y++;
		if (*ptr == 'C')
			map.collects++;
		else if (*ptr == 'P')
		{
			map.player++;
			map.player_p = map.x + map.y;
		}
		else if (*ptr == 'E')
			map.exit++;
		ptr++;
	}
	if (*ptr)
		return (2);
	return ((map.x / map.y) == map.y);
}

static void	get_sprites(t_sprites *sprites, void *mlx)
{
	specific_one(sprites->collect, mlx, PATH_C);
	specific_one(sprites->ground, mlx, PATH_0);
	specific_one(sprites->player, mlx, PATH_P);
	specific_one(sprites->wall, mlx, PATH_1);
	specific_one(sprites->exit, mlx, PATH_E);
}

static void	specific_one(t_img *img, void *mlx, char *path)
{
	int	height;
	int	width;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img->height = height;
	img->width = width;
}
