/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:54:26 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/28 12:54:26 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_everything(t_game *game);

void	exit_game(char *message, int status, t_game *game)
{
	if (status)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(message, 2);
	}
	else
		ft_putstr_fd(message, 1);
	destroy_everything(game);
	exit(status);
}

static void	destroy_everything(t_game *game)
{
	if (!game)
		return ;
	if (game->sprites->collect)
		mlx_destroy_image(game->mlx, game->sprites->collect);
	if (game->sprites->ground)
		mlx_destroy_image(game->mlx, game->sprites->ground);
	if (game->sprites->wall)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->player)
		mlx_destroy_image(game->mlx, game->sprites->player);
	if (game->sprites->way_out)
		mlx_destroy_image(game->mlx, game->sprites->way_out);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	if (game->sprites)
		free(game->sprites);
	if (game->mlx)
		free(game->mlx);
	if (game->map.content)
		free(game->map.content);
	game->map.content = 0;
	game->sprites = 0;
	game->mlx = 0;
}
