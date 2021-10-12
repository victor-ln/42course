/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:03:42 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 11:09:48 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		move_enemy(t_game *game, size_t to, int to_x, int to_y);
static void		start_game(t_game *game);
static int		animation(t_game *game);

/*
	The core, starts the game, hooks the keys pressed,
	closes the window and keeps display in looping.
*/
int	main(int argc, char *argv[])
{
	t_game	*game;

	game = (t_game *)malloc(sizeof(t_game));
	if (!game)
		error(0, "Malloc failed for game struct", strerror(errno));
	load_map(game, check_input(argc, argv[argc - 1]));
	start_game(game);
	mlx_key_hook(game->win, key_press, game);
	mlx_hook(game->win, 17, 0L, close_window, game);
	mlx_loop_hook(game->mlx, animation, game);
	mlx_loop(game->mlx);
}

/*
	Calls the key functions of the game.
*/
static void	start_game(t_game *game)
{
	init_structure(game);
	init_map(game);
	load_environment(game);
	render_game(game);
}

static int	animation(t_game *game)
{
	int	i;
	int	frames;
	int	move;

	while (frames < 4)
	{
		i = -1;
		while (++i < game->coins)
		{
			if (game->coins[i].x && game->coins[i].y)
				mlx_put_image_to_window(game->mlx, game->win, \
			game->sprites->coins[frames], game->coins[i].x, game->coins[i].y);
		}
	}
	if (!enemy_can_play(game))
		return (0);
	move = my_rand() % 20;
	if (move == RIGHT)
		move_enemy(game, RIGHT, 1, 0);
	else if (move == LEFT)
		move_enemy(game, LEFT, -1, 0);
	else if (move == UP)
		move_enemy(game, UP, 0, -1);
	else if (move == DOWN)
		move_enemy(game, DOWN, 0, 1);
	return (0);
}

static void	move_enemy(t_game *g, size_t to, int to_x, int to_y)
{
	int	steps;
	int	x;
	int	y;

	steps = -1;
	x = g->enemy.x / 32;
	y = g->enemy.y / 32;
	display_game(g, g->sprites->enemy[to]->idle, g->enemy.x, g->enemy.y);
	g->stopped[1] = to;
	if (ft_strchr("EC1", g->map[y + to_y][x + to_x]))
		return ;
	while (++steps <= 7)
	{
		g->enemy.x += (to_x * 4);
		g->enemy.y += (to_y * 4);
		if (steps == 7)
			break ;
		display_game(g, g->sprites->enemy[to]->walk[steps % 4], \
			g->enemy.x, g->enemy.y);
		if (g->enemy.x == g->hero.x && g->enemy.y == g->hero.y)
			exit_game(g, "GAME OVER\nYOU LOSE");
	}
	display_game(g, g->sprites->enemy[to]->idle, g->enemy.x, g->enemy.y);
}

void	init_map(t_game *game)
{
	map_dimension(game);
	map_validation(game);
	game->map = (char **)malloc(sizeof(char *) * game->height);
	game->coins = (t_coord **)malloc(sizeof(t_coord *) * game->coins_n);
	if (!game->map || !game->coins)
		error(game, "Malloc for map/coins matrix failed", strerror(errno));
	map_matrix(game);
	free(game->map_b);
	game->map_b = 0;
}
