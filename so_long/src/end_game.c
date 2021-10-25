/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:42:02 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/25 06:40:47 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_sprites(t_img **images, void *mlx, int x);
static void	destroy_struct(t_game *game);
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
	{
		destroy_game(game);
		free(game);
	}
	exit(EXIT_FAILURE);
}

void	exit_game(t_game *game, char *message)
{
	ft_putendl_fd(message, 1);
	destroy_game(game);
	free(game);
	exit(EXIT_SUCCESS);
}

static void	destroy_sprites(t_img **images, void *mlx, int x)
{
	int		i;

	i = 0;
	if (images)
	{
		while (i < x)
		{
			if (images[i])
				mlx_destroy_image(mlx, images[i]);
			i++;
		}
		free(images);
	}
}

static void	destroy_game(t_game *game)
{
	destroy_struct(game);
	if (game->sprites.door)
		destroy_sprites(game->sprites.door, game->mlx, 2);
	if (game->sprites.coins)
		destroy_sprites(game->sprites.coins, game->mlx, 4);
	if (game->sprites.hero)
		free(game->sprites.hero);
	if (game->sprites.enemy)
		free(game->sprites.enemy);
	if (game->enemies)
		free(game->enemies);
	if (game->moves_str)
		free(game->moves_str);
	if (!game->mlx)
		return ;
	if (game->sprites.grass)
		mlx_destroy_image(game->mlx, game->sprites.grass);
	if (game->sprites.tree)
		mlx_destroy_image(game->mlx, game->sprites.tree);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->screen)
		mlx_destroy_window(game->mlx, game->screen);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	destroy_struct(t_game *game)
{
	int		i;

	if (game->map)
	{
		i = 0;
		while (i < game->height)
		{
			if (game->map[i])
				free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	if (game->map_ber)
		free(game->map_ber);
	i = 0;
	while (i < 4)
	{
		if (game->sprites.hero)
			destroy_sprites(game->sprites.hero[i], game->mlx, 7);
		if (game->sprites.enemy)
			destroy_sprites(game->sprites.enemy[i], game->mlx, 5);
		i++;
	}
}
