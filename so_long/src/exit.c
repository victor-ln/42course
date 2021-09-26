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
static void	free_struct(void *ptr, int len);

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
	if (s_game->mlx)
		free(s_game->mlx);
	if (s_game->win)
		free(s_game->win);
	if (s_game->map.map)
		free(s_game->map.map);
	if (s_game->moved_str)
		free(s_game->moved_str);
	free_struct(&s_game->sprites, 5);
}

static void	free_struct(void *ptr, int len)
{
	while (--len > -1)
		if (((char *)ptr + len))
			free(((char *)ptr + len));
}
