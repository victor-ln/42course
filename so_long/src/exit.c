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

static void	free_game(t_game *game);

void	exit_game(char *message, int status, t_game *game)
{
	if (status)
	{
		write(2, "Error\n", 6);
		while (*message)
			write(2, message++, 1);
	}
	else
		while (*message)
			write(1, message++, 1);
	free_game(game);
	exit(status);
}

static void	free_game(t_game *game)
{
	if (!game->mlx)
		free(game->mlx);
	if (!game->win)
		free(game->win);
	if (!game->image)
		free(game->image);
	if (!game->map.content)
		free(game->map.content);
	if (!game->sprites.collect)
		free(game->sprites.collect);
	if (!game->sprites.way_out)
		free(game->sprites.way_out);
	if (!game->sprites.ground)
		free(game->sprites.ground);
	if (!game->sprites.player)
		free(game->sprites.player);
	if (!game->sprites.wall)
		free(game->sprites.wall);
}
