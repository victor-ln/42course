/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way_out.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:15:14 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/24 00:15:14 by vlima-nu         ###   ########.fr       */
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
	way_out(status);
}

static void	free_game(t_game *game)
{
	if (game->mlx != NULL)
		free(game->mlx);
	if (game->win != NULL)
		free(game->win);
	if (game->image != NULL)
		free(game->image);
	if (game->map.content != NULL)
		free(game->map.content);
	if (game->sprites.collect != NULL)
		free(game->sprites.collect);
	if (game->sprites.way_out != NULL)
		free(game->sprites.way_out);
	if (game->sprites.ground != NULL)
		free(game->sprites.ground);
	if (game->sprites.player != NULL)
		free(game->sprites.player);
	if (game->sprites.wall != NULL)
		free(game->sprites.wall);
}
