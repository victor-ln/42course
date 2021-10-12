/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:41:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 11:02:00 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player(t_game *game, size_t direction, int to_x, int to_y);
static void	apply_changes(t_game *game, size_t direction);

int	close_window(int keycode, t_game *game)
{
	(void)keycode;
	exit_game(game, "Window closed\n");
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == 'd')
		move_player(game, RIGHT, 1, 0);
	else if (keycode == 'a')
		move_player(game, LEFT, -1, 0);
	else if (keycode == 'w')
		move_player(game, UP, 0, -1);
	else if (keycode == 's')
		move_player(game, DOWN, 0, 1);
	else if (keycode == ESC)
		exit_game(game, "ESC pressed\n");
	return (0);
}

/*
	If the player position is the same that the enemy one the game is over.
	If the coins is where the player moved
	decreases its variable and draws the ground instead the coins.
	Draws the exit door opened if coins is 0.
	Also if coins is 0 and the player moved to the exit,
	then exits the game successfully.
	Finally displays the player in the moved position and the number of movements.
*/
static void	apply_changes(t_game *game, size_t direction)
{
	int		x;
	int		y;
	int		i;

	x = game->hero.x / 32;
	y = game->hero.y / 32;
	game->movements++;
	if (game->hero.x == game->enemy.x && game->hero.y == game->enemy.y)
		exit_game(game, "GAME OVER\nYOU LOSE");
	if (game->map[y][x] == 'C')
	{
		i = 0;
		while (game->coins[i].x != game->hero.x && \
			game->coins[i].y != game->hero.y)
			i++;
		ft_bzero(&game->coins[i], 2);
		if (--game->coins_n == 0)
			draw_sprite(game->img, game->sprites->door_o,
				game->exit.x, game->exit.y);
	}
	if (game->map[y][x] != 'E')
		game->map[y][x] = '0';
	else if (!game->coins_n)
		exit_game(game, "YOU WIN !\n");
	display_game(game, game->sprites->hero[direction]->idle, x, y);
}

/*

*/
static void	move_player(t_game *g, size_t to, int to_x, int to_y)
{
	int		steps;
	int		x;
	int		y;

	steps = -1;
	display_game(g, g->sprites->hero[to]->idle, g->hero.x, g->hero.y);
	x = g->hero.x / 32;
	y = g->hero.y / 32;
	if (g->map[y + to_y][x + to_x] == '1'
		|| (g->map[y + to_y][x + to_x] == 'E' && g->coins_n))
		return ;
	g->stopped[0] = -1;
	g->map[y][x] = '0';
	while (++steps <= 7)
	{
		g->hero.x += (to_x * 4);
		g->hero.y += (to_x * 4);
		if (steps == 7)
			break ;
		display_game(g, g->sprites->hero[to]->walk[steps % 6], x, y);
		if (g->hero.x == g->enemy.x && g->hero.y == g->enemy.y)
			exit_game(g, "GAME OVER\nYOU LOSE");
	}
	apply_changes(g, to);
	g->stopped[0] = to;
}

void	display_game(t_game *g, t_img *in_move, int x, int y)
{
	char		*temp;
	void		*idle;

	temp = ft_utoa(g->movements);
	if (g->stopped[0] < 0)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
		idle = g->sprites->enemy[g->stopped[1]]->idle;
		mlx_put_image_to_window(g->mlx, g->win, idle, g->enemy.x, g->enemy.y);
		mlx_put_image_to_window(g->mlx, g->win, in_move, x, y);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
		idle = g->sprites->hero[g->stopped[0]]->idle;
		mlx_put_image_to_window(g->mlx, g->win, idle, g->hero.x, g->hero.y);
		mlx_put_image_to_window(g->mlx, g->win, in_move, x, y);
	}
	mlx_string_put(g->mlx, g->win, 10, 10, 0xFFFFFF, "Moved :");
	mlx_string_put(g->mlx, g->win, 60, 10, 0XFFFFFF, temp);
	free(temp);
}
