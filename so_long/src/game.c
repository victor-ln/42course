/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 10:36:36 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/27 14:09:03 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	hero_got_caught(t_game *game);

void	game_init(t_game *game)
{
	if (!game)
		error(0, "Malloc for game struct failed", strerror(errno));
	ft_bzero(&game->sprites, sizeof(t_sprites));
	ft_bzero(game, sizeof(t_game));
}

void	start_game(t_game *game)
{
	display_game(game);
	mlx_hook(game->screen, 17, 0L, close_window, game);
	mlx_expose_hook(game->screen, reload_image, game);
	mlx_hook(game->screen, 02, 1L, key_press, game);
	mlx_do_key_autorepeatoff(game->mlx);
	mlx_expose_hook(game->screen, reload_image, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}

void	display_game(t_game *game)
{
	if (game->kills == game->enemies_num && !game->coins_num)
		game->door = 1;
	draw_game(game);
	mlx_do_sync(game->mlx);
	mlx_put_image_to_window(game->mlx, game->screen, game->img, 0, 0);
	hero_got_caught(game);
	move_enemies(game);
	if (BONUS)
	{
		if (++game->frame == 8)
			game->frame = 0;
		ft_delay(45500);
		mlx_string_put(game->mlx, game->screen, 10, 10, C_WHITE, "Moves :");
		mlx_string_put(game->mlx, game->screen, 60, 10, C_WHITE, \
			game->moves_str);
	}
}

/*
	Checks if the hero has been caught by an enemy.
*/
static void	hero_got_caught(t_game *g)
{
	int		i;

	i = 0;
	while (i < g->enemies_num)
	{
		if ((g->hero.x == g->enemies[i].x && \
			g->hero.y == g->enemies[i].y) || \
			(g->hero.x == g->enemies[i].x - g->enemies[i].to_x * 4 && \
			g->hero.y == g->enemies[i].y - g->enemies[i].to_y * 4) || \
			(g->hero.x == g->enemies[i].x + g->enemies[i].to_x * 4 && \
			g->hero.y == g->enemies[i].y + g->enemies[i].to_y * 4))
			exit_game(g, "You lose");
		i++;
	}
}

int	animation(t_game *game)
{
	if (BONUS)
		display_game(game);
	game->hero.step = 0;
	return (0);
}
