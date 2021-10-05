/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:49:55 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 21:54:13 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_game(t_game *game);

void	error(t_game *game, char *message, int error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(strerror(error), 2);
	free_game(game);
	exit(1);
}

void	exit_game(t_game *game, char *message)
{
	ft_putstr_fd(message, 1);
	free_game(game);
	exit(0);
}

static void	free_game(t_game *game)
{
	if (!game)
		return ;
	free(game->map);
	if (game->win != 0)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img != 0)
		mlx_destroy_image(game->mlx, game->img);
	if (game->sprites->collectible != 0)
		mlx_destroy_image(game->mlx, game->sprites->collectible);
	if (game->sprites->ground != 0)
		mlx_destroy_image(game->mlx, game->sprites->ground);
	if (game->sprites->player != 0)
		mlx_destroy_image(game->mlx, game->sprites->player);
	if (game->sprites->wall != 0)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->way_out != 0)
		mlx_destroy_image(game->mlx, game->sprites->way_out);
	if (game->mlx != 0)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	if (game->sprites != NULL)
		free(game->sprites);
	free(game);
}

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
		write(fd, s++, 1);
}
