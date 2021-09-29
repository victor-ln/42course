/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:22:59 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/29 00:22:59 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_sprites(t_game *game);
static void	check_for_map_errors(t_game *game, int status);
static void	specific_one(t_img **img, void *mlx, char *path);
static int	save_map_info(t_map *map, size_t player, size_t exits);

void	ft_start_game(t_game *game)
{
	check_for_map_errors(game, save_map_info(&game->map, 0, 0));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game("Mlx_init got NULL\n", 1, game);
	game->win = mlx_new_window(game->mlx, (game->map.width - 1) * 32, \
		(game->map.height - 1) * 32, "so_long");
	game->image = mlx_new_image(game->mlx, (game->map.width - 1) * 32, \
		(game->map.height - 1) * 32);
	if (!game->win)
		exit_game("Couldn't create a window\n", 1, game);
	if (!game->image)
		exit_game("Couldn't create an image\n", 1, game);
	get_sprites(game);
	ft_render(game);
	game->map.width++;
}

static void	check_for_map_errors(t_game *g, int status)
{
	if (status == 1)
		exit_game(INVALID_CHAR, 1, g);
	if (is_end_after_c(g->map.content, '1', '\n') || status == 2)
		exit_game(N_SURROUNDED, 1, g);
	g->map.width = g->map.area / g->map.height;
	g->map.content += g->map.area + g->map.height - 1 - g->map.width * 2;
	if (is_end_after_c(g->map.content, '1', 0))
		exit_game(N_SURROUNDED, 1, g);
	if (g->map.area % g->map.height || status == 3)
		exit_game(DIFF_IN_LEN, 1, g);
	if (g->map.width == g->map.height)
		exit_game(SQUARE, 1, g);
	if (g->map.height < 3 || g->map.width < 3)
		exit_game(N_ENOUGH_L, 1, g);
	if (status == 4)
		exit_game(N_VALID, 1, g);
}

/*
	Map example:

	0	1	2	3	4	5	columns

	1	1	1	1	1	\n	line 0	0
	1	0	C	P	1	\n	line 1	32
	1	E	1	C	1	\n	line 2	64
	1	1	1	1	1	\0	line 3	96
	0	32	64	96	128	
*/

static int	save_map_info(t_map *map, size_t player, size_t exits)
{
	while (strchr(MAP, *map->content))
	{
		if (*map->content != '\n')
			map->area++;
		else if (*(map->content + 1) != '1' || *(map->content - 1) != '1')
			return (2);
		else if (map->area % map->height)
			return (3);
		else
			map->height++;
		if (*map->content == 'C')
			map->collects++;
		else if (*map->content == 'P')
		{
			player++;
			map->player_p = (map->area - 1) + (map->height - 1);
		}
		else if (*map->content == 'E')
			exits++;
		map->content++;
	}
	if (exits != 1 || player != 1 || !map->collects)
		return (4);
	return (*map->content != 0);
}

static void	get_sprites(t_game *game)
{
	specific_one(&game->sprites->player, game->mlx, "./img/player.xpm");
	specific_one(&game->sprites->collect, game->mlx, "./img/collect.xpm");
	specific_one(&game->sprites->way_out, game->mlx, "./img/exit.xpm");
	specific_one(&game->sprites->wall, game->mlx, "./img/wall.xpm");
	specific_one(&game->sprites->ground, game->mlx, "./img/ground.xpm");
	if (!game->sprites->collect || !game->sprites->way_out \
	|| !game->sprites->ground || !game->sprites->player || !game->sprites->wall)
		exit_game("Sprites got NULL\n", 1, game);
}

static void	specific_one(t_img **img, void *mlx, char *path)
{
	int	height;
	int	width;

	*img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	(*img)->height = height;
	(*img)->width = width;
}
