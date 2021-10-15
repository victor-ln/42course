/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:42:02 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 21:18:54 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_characters(t_moves **player, void *display, int size);
static void	destroy_structs(t_game *game);
static void	destroy_game(t_game *game);

void	error(t_game *game, char *message, char *str_error)
{
	if (message)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(message, 2);
		ft_putendl_fd(str_error, 2);
	}
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

static void	destroy_characters(t_moves **character, void *display, int size)
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
		while (frames < size)
		{
			if (character[directions]->walk[frames])
				mlx_destroy_image(display, character[directions]->walk[frames]);
			frames++;
		}
		if (character[directions]->idle)
			mlx_destroy_image(display, character[directions]->idle);
		free(character[directions]);
		directions++;
	}
	free(character);
}

static void	destroy_game(t_game *game)
{
	if (game->screen)
		mlx_destroy_window(game->display, game->screen);
	if (game->map_img)
		mlx_destroy_image(game->display, game->map_img);
	if (game->sprites.coins)
		mlx_destroy_image(game->display, game->sprites.coins);
	if (game->sprites.grass)
		mlx_destroy_image(game->display, game->sprites.grass);
	if (game->sprites.tree)
		mlx_destroy_image(game->display, game->sprites.tree);
	if (game->sprites.door_o)
		mlx_destroy_image(game->display, game->sprites.door_o);
	destroy_characters(game->sprites.enemy, game->display, 4);
	destroy_characters(game->sprites.hero, game->display, 6);
	destroy_structs(game);
	if (game->moves_str)
		free(game->moves_str);
	if (game->display)
	{
		mlx_destroy_display(game->display);
		free(game->display);
	}
	free(game);
}

static void	destroy_structs(t_game *game)
{
	int		i;

	if (game->map_b)
		free(game->map_b);
	game->map_b = 0;
	if (game->coins)
		free(game->coins);
	if (game->enemies)
		free(game->enemies);
	if (game->enemies)
		free(game->enemies);
	i = -1;
	while (++i < 4)
		if (game->coins_img[i])
			mlx_destroy_image(game->display, game->coins_img[i]);
	if (!game->map)
		return ;
	i = -1;
	while (++i < game->height)
	{
		if (game->map[i])
			free(game->map[i]);
		game->map[i] = 0;
	}
	free(game->map);
}
