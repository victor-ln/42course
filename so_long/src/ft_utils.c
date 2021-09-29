/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:23:48 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/29 00:23:48 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_everything(t_game *game);

void	ft_start_struct(t_game *game)
{
	game->sprites = (t_sprites *)malloc(sizeof(t_sprites));
	if (!game->sprites)
		exit_game("Malloc failed\n", 1, game);
	ft_bzero(game->sprites, 5);
	ft_bzero(game, 5);
	game->map_info.collects = 0;
	game->map_info.height = 1;
	game->map_info.area = 1;
	game->image = 0;
}

int	is_end_after_c(char *s, char c, char end)
{
	while (*s == c)
		s++;
	return (*s != end);
}

void	exit_game(char *message, int status, t_game *game)
{
	destroy_everything(game);
	if (status)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd(message, 2);
	}
	else
		ft_putstr_fd(message, 1);
	if (game->mlx != NULL)
		free(game->mlx);
	if (game->sprites != NULL)
		free(game->sprites);
	if (game->map != NULL)
		free(game->map);
	game->map = 0;
	game->sprites = 0;
	game->mlx = 0;
	exit(status);
}

static void	destroy_everything(t_game *game)
{
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
}

void	check_argc(int argc)
{
	if (argc != 2)
	{
		perror("Error\nInvalid number of arguments");
		exit(1);
	}
}
