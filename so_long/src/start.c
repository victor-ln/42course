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

static int	init_map(t_map *map, char *ptr);
static void	get_sprites(t_sprites *s, void *mlx);
static void	check_map_errors(t_game *game, int status);
static void	specific_one(t_img *img, void *mlx, char *path);

void	start_game(t_game *game)
{
	check_map_errors(game, init_map(&game->map, game->map.content));
	game->mlx = mlx_init();
	if (game->mlx == NULL)
		exit_game("Mlx_init got NULL\n", EXIT_FAILURE, game);
	game->win = mlx_new_window(game->mlx,
			(game->map.area / game->map.height) * 64, game->map.height * 64,
			"so_long");
	if (game->win == NULL)
		exit_game("Couldn't create a window\n", EXIT_FAILURE, game);
	game->image = mlx_new_image(game->mlx,
			(game->map.area / game->map.height) * 64, game->map.height * 64);
	if (game->image == NULL)
		exit_game("Couldn't create an image\n", EXIT_FAILURE, game);
	get_sprites(&game->sprites, game->mlx);
	if (!game->sprites.collect || !game->sprites.exit || !game->sprites.ground
		|| !game->sprites.player || !game->sprites.wall)
		exit_game("Sprites got NULL\n", EXIT_FAILURE, game);
	render(game);
}

static void	check_map_errors(t_game *game, int status)
{
	if ((game->map.area / game->map.height) == game->map.height)
		exit_game("Invalid map, it's a square\n", 1, game);
	if (status == 2)
		exit_game("Invalid map, unknown char or map not surrounded by walls\n",
			1, game);
	if (status == 4 || game->map.area % game->map.height)
		exit_game("Invalid map, it's not rectangular\n", 1, game);
	if (game->map.height < 3 || ((game->map.area / game->map.height) < 3))
		exit_game("Invalid map, not enough lines\n", 1, game);
	game->map.content += (game->map.area + game->map.height - 1)
		- (game->map.area / game->map.height);
	while (*game->map.content == '1')
		game->map.content++;
	if (status == 3 || *game->map.content)
		exit_game("Invalid map, it's not surrounded by walls\n", 1, game);
	if (game->map.exit != 1 || game->map.player != 1 || !game->map.collects)
		exit_game("Invalid map, it needs an exit, a player and collects\n",
			1, game);
}

/*
	Map example:

	1	1	1	1	1	\n
	1	0	C	P	1	\n
	1	E	1	C	1	\n
	1	1	1	1	1	\0

*/

static int	init_map(t_map *map, char *ptr)
{
	while ((strchr(MAP, *ptr) && map->height > 1)
		|| (map->height == 1 && *ptr == '1'))
	{
		if (*ptr != '\n')
			map->area++;
		else if (*(ptr + 1) != '1' || *(ptr - 1) != '1')
			return (3);
		else if (map->area % map->height)
			return (4);
		else
			map->height++;
		if (*ptr == 'C')
			map->collects++;
		else if (*ptr == 'P')
		{
			map->player++;
			map->player_p = (map->area - 1) + (map->height - 1);
		}
		else if (*ptr == 'E')
			map->exit++;
		ptr++;
	}
	if (*ptr)
		return (2);
	return (EXIT_SUCCESS);
}

static void	get_sprites(t_sprites *sprites, void *mlx)
{
	specific_one(sprites->player, mlx, PATH_P);
	specific_one(sprites->collect, mlx, PATH_C);
	specific_one(sprites->exit, mlx, PATH_E);
	specific_one(sprites->wall, mlx, PATH_1);
	specific_one(sprites->ground, mlx, PATH_0);
}

static void	specific_one(t_img *img, void *mlx, char *path)
{
	int	height;
	int	width;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	img->height = height;
	img->width = width;
}
