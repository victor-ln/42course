/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:57:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/27 03:51:43 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	hit_enemies(t_game *game, int i);
static void	move_arrows(t_game *game);
static void	realloc_arrows(t_coord **arrows, short arrows_num);

void	draw_arrows(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	j = game->arrows_num;
	if (game->arrows_num)
	{
		move_arrows(game);
		while (i < j)
		{
			if (game->arrow[i].x && game->arrow[i].y)
				draw_sprite(game->img, game->sprites.arrow[game->arrow[i].dir], \
					game->arrow[i].x, game->arrow[i].y);
			i++;
		}
	}
	if (!game->arrows_num && game->arrow)
	{
		free(game->arrow);
		game->arrow = 0;
	}
}

void	put_arrow(t_game *game)
{
	int		current;

	current = game->arrows_num;
	if (!game->arrow)
		game->arrow = (t_coord *)malloc(sizeof(t_coord) * ++game->arrows_num);
	else
		realloc_arrows(&game->arrow, game->arrows_num++);
	if (!game->arrow)
		error(game, "Malloc for arrows struct failed", strerror(errno));
	game->arrow[current].to_x = 0;
	game->arrow[current].to_y = 0;
	game->arrow[current].dir = game->hero.dir;
	if (game->hero.dir == RIGHT)
		game->arrow[current].to_x = 8;
	else if (game->hero.dir == LEFT)
		game->arrow[current].to_x = -8;
	else if (game->hero.dir == UP)
		game->arrow[current].to_y = -8;
	else
		game->arrow[current].to_y = 8;
	game->arrow[current].x = game->hero.x;
	game->arrow[current].y = game->hero.y;
}

static void	realloc_arrows(t_coord **arrows, short arrows_num)
{
	void	*bkp;
	short	size;

	size = arrows_num;
	bkp = malloc(sizeof(t_coord) * size);
	ft_memcpy(bkp, *arrows, sizeof(t_coord) * size);
	free(*arrows);
	*arrows = (t_coord *)malloc(sizeof(t_coord) * ++size);
	ft_memcpy(*arrows, bkp, sizeof(t_coord) * (size - 1));
	free(bkp);
}

static void	move_arrows(t_game *g)
{
	int		x;
	int		y;
	int		i;
	int		j;

	i = -1;
	j = g->arrows_num;
	while (++i < j)
	{
		if (!g->arrow[i].x && !g->arrow[i].y)
			continue ;
		x = g->arrow[i].x / 32;
		y = g->arrow[i].y / 32;
		if ((g->map[y][x] && g->map[y][x] != ENEMY) || hit_enemies(g, i))
		{
			g->arrows_num--;
			g->arrow[i].x = 0;
			g->arrow[i].y = 0;
		}
		else
		{
			g->arrow[i].x += g->arrow[i].to_x;
			g->arrow[i].y += g->arrow[i].to_y;
		}
	}
}

static int	hit_enemies(t_game *game, int j)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < game->enemies_num)
	{
		if ((game->arrow[j].x == game->enemies[i].x && \
			game->arrow[j].y == game->enemies[i].y) || \
			(game->arrow[j].x - game->arrow[j].to_x == game->enemies[i].x && \
			game->arrow[j].y - game->arrow[j].to_y == game->enemies[i].y) || \
			((game->arrow[j].x + game->arrow[j].to_x == game->enemies[i].x && \
			game->arrow[j].y + game->arrow[j].to_y == game->enemies[i].y)))
		{
			x = game->enemies[i].x / 32;
			y = game->enemies[i].y / 32;
			game->enemies[i].is_alive = -1;
			game->enemies[i].step = 0;
			game->map[y][x] = 0;
			return (1);
		}
		i++;
	}
	return (0);
}
