/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:41:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 22:58:51 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	apply_changes(t_game *game);

int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	exit_game(game, "Window closed\n");
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 'd')
		player_moving(game, game->sprites->player_d[RIGHT], 1, 0);
	else if (keycode == 'a')
		player_moving(game, game->sprites->player_d[LEFT], -1, 0);
	else if (keycode == 'w')
		player_moving(game, game->sprites->player_d[UP], 0, -1);
	else if (keycode == 's')
		player_moving(game, game->sprites->player_d[DOWN], 0, 1);
	else if (keycode == ESC)
		exit_game(game, "ESC pressed\n");
	return (0);
}

/*
** Receives the direction to move.
** If the direction points to a wall,
** it does nothing, else renders the game later
** to change player position value to "0" and
** direction plus player position value to "P" on the map.
** Checks if the collects is in the direction and
** decreases its variable if it is.
** If the collection is 0 and the direction points to the exit,
** then exits the game successfully.
*/
static void	apply_changes(t_game *game)
{
	char	*temp;

	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collects--;
		if (game->collects < 5)
		{
			temp = ft_utoa(5 - game->collects);
			mlx_destroy_image(game->mlx, game->sprites->way_out);
			load_sprite(&game->sprites->way_out, game->mlx, \
				ft_strcat("./sprites/exit/", temp));
			free(temp);
			draw_sprite(game->img, game->sprites->way_out, \
				game->exit.x, game->exit.y);
		}
	}
	else if (game->map[game->player.y][game->player.x] == 'E')
		if (!game->collects)
			exit_game(game, "YOU WIN !\n");
	if (game->map[game->player.y][game->player.x] != 'E')
		game->map[game->player.y][game->player.x] = 'P';
	move_display(game);
}

static void	player_moving(t_game *g, t_player *direction, int to_x, int to_y)
{
	int	frame;

	frame = 16;
	g->map[g->player.y][g->player.x] = '0';
	while (frame <= 48)
	{
		draw_sprite(g->img, g->sprites->ground, \
			g->player.x * 64, g->player.y * 64);
		if (frame > 16)
			draw_image(g, g->player.x + to_x, g->player.y + to_y);
		draw_sprite(g->img, direction->moves[frame % 2], g->player.x * 64 \
			+ (to_x * frame), g->player.y * 64 + (to_y * frame));
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
		frame += 16;
	}
	g->player.x += to_x;
	g->player.y += to_y;
	apply_changes(g);
}

void	move_display(t_game *game)
{
	char	*temp;

	temp = ft_utoa(game->movements++);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moved :");
	mlx_string_put(game->mlx, game->win, 60, 10, 0XFFFFFF, temp);
	free(temp);
}
