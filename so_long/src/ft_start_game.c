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
static int	save_map_info(t_map *map_info, char *map);

void	ft_start_game(t_game *game)
{
	check_for_map_errors(game, save_map_info(&game->map_info, game->map));
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game("Mlx_init got NULL\n", 1, game);
	game->win = mlx_new_window(game->mlx, (game->map_info.width - 1) * 32, \
		(game->map_info.height - 1) * 32, "so_long");
	game->image = mlx_new_image(game->mlx, (game->map_info.width - 1) * 32, \
		(game->map_info.height - 1) * 32);
	if (!game->win)
		exit_game("Couldn't create a window\n", 1, game);
	if (!game->image)
		exit_game("Couldn't create an image\n", 1, game);
	get_sprites(game);
	ft_render(game);
	game->map_info.width++;
}

static void	check_for_map_errors(t_game *g, int status)
{
	if (status == 1)
		exit_game(INVALID_CHAR, 1, g);
	if (is_end_after_c(g->map, '1', '\n') || status == 2)
		exit_game(N_SURROUNDED, 1, g);
	g->map_info.width = g->map_info.area / g->map_info.height;
	g->map += g->map_info.area + g->map_info.height - 1 - g->map_info.width * 2;
	if (is_end_after_c(g->map, '1', 0))
		exit_game(N_SURROUNDED, 1, g);
	if (g->map_info.area % g->map_info.height || status == 3)
		exit_game(N_RECTANGLE, 1, g);
	if (g->map_info.width == g->map_info.height)
		exit_game(SQUARE, 1, g);
	if (g->map_info.height < 3 || g->map_info.width < 3)
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

static int	save_map_info(t_map *map_info, char *map)
{
	size_t	aux;

	aux = 0;
	while (strchr(MAP, *map))
	{
		if (*map != '\n')
			map_info->area++;
		else if (*(map + 1) != '1' || *(map - 1) != '1'
			|| ((map_info->area % map_info->height) != 0))
			return ((map_info->area % map_info->height) + 2);
		else
			map_info->height++;
		if (*map == 'C')
			map_info->collects++;
		else if (*map == 'E' && !aux)
			aux++;
		else if (*map == 'P' && !map_info->player_p)
			map_info->player_p = (map_info->area - 1) + (map_info->height - 1);
		else if ((aux != 1 || map_info->player_p) && !ft_strchr("01", *map))
			return (4);
		map++;
	}
	return (*map != 0);
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
