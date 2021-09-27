/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:15:14 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/24 00:15:14 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_game(t_game *s_game);

int	exit_game(char *message, int status, t_game *s_game)
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
	free_game(s_game);
	exit(status);
}

static void	free_game(t_game *s_game)
{
	if (s_game->mlx != NULL)
		free(s_game->mlx);
	if (s_game->win != NULL)
		free(s_game->win);
	if (s_game->map.content != NULL)
		free(s_game->map.content);
	if (s_game->moved_str != NULL)
		free(s_game->moved_str);
	if (s_game->sprites.collect != NULL)
		free(s_game->sprites.collect);
	if (s_game->sprites.exit != NULL)
		free(s_game->sprites.exit);
	if (s_game->sprites.ground != NULL)
		free(s_game->sprites.ground);
	if (s_game->sprites.player != NULL)
		free(s_game->sprites.player);
	if (s_game->sprites.wall != NULL)
		free(s_game->sprites.wall);
}
