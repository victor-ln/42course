/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:42:02 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 02:32:33 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_character_sprites(t_moves **player, void *mlx);
static void	destroy_structs(t_game *game);
static void	destroy_game(t_game *game);

void	error(t_game *game, char *message, char *str_error)
{
	if (message)
		ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	ft_putendl_fd(str_error, 2);
	if (game)
		destroy_game(game);
	exit(1);
}

void	exit_game(t_game *game, char *message)
{
	ft_putendl_fd(message, 1);
	destroy_game(game);
	exit(0);
}

static void	destroy_character_sprites(t_moves **character, void *mlx)
{
	int		directions;
	int		frames;

	if (!character)
		return ;
	directions = 0;
	while (directions < 4)
	{
		if (!character[directions])
			continue ;
		frames = 0;
		while (frames < 6)
		{
			if (character[directions]->walk[frames])
				mlx_destroy_image(mlx, character[directions]->walk[frames]);
			frames++;
		}
		if (character[directions]->idle)
			mlx_destroy_image(mlx, character[directions]->idle);
		free(character[directions]);
		directions++;
	}
	free(character);
}

static void	destroy_game(t_game *game)
{
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->sprites->coins)
		mlx_destroy_image(game->mlx, game->sprites->coins);
	if (game->sprites->grass)
		mlx_destroy_image(game->mlx, game->sprites->grass);
	if (game->sprites->tree)
		mlx_destroy_image(game->mlx, game->sprites->tree);
	if (game->sprites->door_o)
		mlx_destroy_image(game->mlx, game->sprites->door_o);
	destroy_character_sprites(game->sprites->enemy, game->mlx);
	destroy_character_sprites(game->sprites->hero, game->mlx);
	destroy_structs(game);
	if (game->sprites)
		free(game->sprites);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}

static void	destroy_structs(t_game *game)
{
	int		rows;

	if (game->map_b)
		free(game->map_b);
	game->map_b = 0;
	if (game->coins)
		free(game->coins);
	if (!game->map)
		return ;
	rows = 0;
	while (rows < game->height)
	{
		if (game->map[rows])
			free(game->map[rows]);
		game->map[rows] = 0;
		rows++;
	}
	free(game->map);
}
