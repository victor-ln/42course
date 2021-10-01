/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:49:55 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/01 02:44:08 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_game(t_game *game);
static void	ft_putstr_fd(char *s, int fd);

void	primary_errors(char *message, char *str_error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(str_error, 2);
	write(2, "\n", 1);
	exit(1);
}

void	map_error(char *message, char *map)
{
	free(map);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	write(2, "\n", 1);
	exit(1);
}

void	exit_game(t_game *game, char *message, int fd)
{
	if (fd == 2)
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, fd);
	destroy_game(game);
	if (fd == 2)
		exit(1);
	exit(0);
}

static void	destroy_game(t_game *game)
{
	free(game->map);
	if (game->mlx == NULL)
		return ;
	if (game->win != NULL)
		mlx_destroy_window(game->mlx, game->win);
	if (game->image != NULL)
		mlx_destroy_image(game->mlx, game->image);
	if (game->sprites.collectible != NULL)
		mlx_destroy_image(game->mlx, game->sprites.collectible);
	if (game->sprites.ground != NULL)
		mlx_destroy_image(game->mlx, game->sprites.ground);
	if (game->sprites.player != NULL)
		mlx_destroy_image(game->mlx, game->sprites.player);
	if (game->sprites.wall != NULL)
		mlx_destroy_image(game->mlx, game->sprites.wall);
	if (game->sprites.way_out != NULL)
		mlx_destroy_image(game->mlx, game->sprites.way_out);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

static void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
