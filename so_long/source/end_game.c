/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:42:02 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/08 02:22:19 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	destroy_player_images(t_player **player_d, void *mlx);
static void	destroy_game(t_game *game);

void	error(t_game *game, char *message, char *str_error)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd(str_error, 2);
	if (game != 0)
		destroy_game(game);
	exit(1);
}

void	exit_game(t_game *game, char *message)
{
	ft_putstr_fd(message, 1);
	destroy_game(game);
	exit(0);
}

static void	destroy_player_images(t_player **player_d, void *mlx)
{
	int	i;
	int	j;

	if (player_d == 0)
		return ;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 3)
		{
			if (player_d[i]->moves[j] != 0)
				mlx_destroy_image(mlx, player_d[i]->moves[j]);
			j++;
		}
		if (player_d[i]->moves != 0)
			free(player_d[i]->moves);
		if (player_d[i] != 0)
			free(player_d[i]);
		i++;
	}
	free(player_d);
}

static void	destroy_game(t_game *game)
{
	if (game->win != 0)
		mlx_destroy_window(game->mlx, game->win);
	if (game->img != 0)
		mlx_destroy_image(game->mlx, game->img);
	if (game->sprites->collect != 0)
		mlx_destroy_image(game->mlx, game->sprites->collect);
	if (game->sprites->ground != 0)
		mlx_destroy_image(game->mlx, game->sprites->ground);
	if (game->sprites->wall != 0)
		mlx_destroy_image(game->mlx, game->sprites->wall);
	if (game->sprites->way_out != 0)
		mlx_destroy_image(game->mlx, game->sprites->way_out);
	destroy_player_images(game->sprites->player_d, game->mlx);
	if (game->map_b != 0)
		free(game->map_b);
	free_matrix(game->map, game->height);
	if (game->sprites != 0)
		free(game->sprites);
	if (game->mlx != 0)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
}
