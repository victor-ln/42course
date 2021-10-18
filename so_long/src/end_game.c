/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:42:02 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 18:58:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_sprites(t_img ***images, void *display, int x, int y);
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
	if (game != 0)
	{
		destroy_game(game);
		free(game);
	}
	exit(1);
}

void	exit_game(t_game *game, char *message)
{
	ft_putendl_fd(message, 1);
	destroy_game(game);
	free(game);
	exit(0);
}

static void	destroy_sprites(t_img ***images, void *display, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	if (!images)
		return ;
	while (j < y)
	{
		if (images[j])
		{
			i = 0;
			while (i < x)
			{
				if (images[j][i] && display)
					mlx_destroy_image(display, images[j][i]);
				i++;
			}
			free(images[j]);
		}
		j++;
	}
	free(images);
}

static void	destroy_game(t_game *game)
{
	destroy_sprites(&game->sprites.door, game->mlx, 2, 1);
	destroy_sprites(&game->sprites.coins, game->mlx, 4, 1);
	destroy_sprites(game->sprites.hero, game->mlx, 7, 4);
	destroy_sprites(game->sprites.enemy, game->mlx, 5, 4);
	if (game->sprites.hero)
		free(game->sprites.hero);
	if (game->sprites.enemy)
		free(game->sprites.enemy);
	if (game->moves_str)
		free(game->moves_str);
	if (game->screen)
		mlx_destroy_window(game->mlx, game->screen);
	if (game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->sprites.grass)
		mlx_destroy_image(game->mlx, game->sprites.grass);
	if (game->sprites.tree)
		mlx_destroy_image(game->mlx, game->sprites.tree);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	destroy_structs(game);
}

static void	destroy_structs(t_game *game)
{
	int		i;

	if (game->map_ber)
		free(game->map_ber);
	if (game->enemies)
		free(game->enemies);
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
}
