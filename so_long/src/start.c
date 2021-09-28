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

static int	init_map(t_map *map);
static void	get_sprites(t_game *game);
static void	check_map_errors(t_game *game, int status);
static void	specific_one(t_img **img, void *mlx, char *path);

void	start_game(t_game *game)
{
	check_map_errors(game, init_map(&game->map));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game("Mlx_init got NULL\n", EXIT_FAILURE, game);
	game->win = mlx_new_window(game->mlx, game->map.width * 64, \
		game->map.height * 64, "so_long");
	game->image = mlx_new_image(game->mlx, game->map.width * 64, \
		game->map.height * 64);
	if (!game->win)
		exit_game("Couldn't create a window\n", EXIT_FAILURE, game);
	if (!game->image)
		exit_game("Couldn't create an image\n", EXIT_FAILURE, game);
	get_sprites(game);
	render_game(game);
	game->map.width++;
}

static void	check_map_errors(t_game *g, int status)
{
	if (status == 2)
		exit_game(INVALID_CHAR, 1, g);
	if (is_limit_after_c(g->map.content, '1', '\n'))
		exit_game(N_SURROUNDED, 1, g);
	g->map.content = g->map.area + g->map.height - 1 - g->map.width * 2;
	if (status == 3 || is_limit_after_c(g->map.content, '1', '\0'))
		exit_game(N_SURROUNDED, 1, g);
	if (g->map.area % g->map.height || 4)
		exit_game(DIFF_IN_LEN, 1, g);
	if (g->map.width == g->map.height)
		exit_game(SQUARE, 1, g);
	if (g->map.height < 3 || g->map.width < 3)
		exit_game(N_ENOUGH_L, 1, g);
	if (g->map.exits != 1 || g->map.player != 1 || !g->map.collects)
		exit_game(N_VALID, 1, g);
}

static int	init_map(t_map *map)
{
	while (strchr(MAP, *map->content))
	{
		if (*map->content != '\n')
			map->area++;
		else if (*(map->content + 1) != '1' || *(map->content - 1) != '1')
			return (3);
		else if (map->area % map->height)
			return (4);
		else
			map->height++;
		if (*map->content == 'C')
			map->collects++;
		else if (*map->content == 'P')
		{
			map->player++;
			map->player_p = (map->area - 1) + (map->height - 1);
		}
		else if (*map->content == 'E')
			map->exits++;
		map->content++;
	}
	if (*map->content)
		return (2);
	map->width = map->area / map->height;
	return (EXIT_SUCCESS);
}

static void	get_sprites(t_game *game)
{
	specific_one(&game->sprites.player, game->mlx, "./img/player.xpm");
	specific_one(&game->sprites.collect, game->mlx, "./img/collect.xpm");
	specific_one(&game->sprites.way_out, game->mlx, "./img/exit.xpm");
	specific_one(&game->sprites.wall, game->mlx, "./img/wall.xpm");
	specific_one(&game->sprites.ground, game->mlx, "./img/ground.xpm");
	if (!game->sprites.collect || !game->sprites.way_out \
	|| !game->sprites.ground || !game->sprites.player || !game->sprites.wall)
		exit_game("Sprites got NULL\n", EXIT_FAILURE, game);
}

static void	specific_one(t_img **img, void *mlx, char *path)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	(*img)->height = height;
	(*img)->width = width;
}
