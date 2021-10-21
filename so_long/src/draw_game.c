/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:20:03 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/21 03:37:52 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void			draw_players(t_game *game);
static void			draw_sprite(t_img *image, t_img *sprite, int x, int y);
static void			draw_pixel(t_img *image, int x, int y, unsigned int color);
static unsigned int	get_color(t_img *image, int x, int y);

void	draw_game(t_game *g)
{
	int		x;
	int		y;

	y = -1;
	while (++y < g->height)
	{
		x = -1;
		while (++x < g->width)
		{
			draw_sprite(g->img, g->sprites.grass, x * 32, y * 32);
			if (g->map[y][x] == 1)
				draw_sprite(g->img, g->sprites.tree, x * 32, y * 32);
			else if (g->map[y][x] == COLL)
				draw_sprite(g->img, g->sprites.coins[g->frame], x * 32, y * 32);
			else if (g->map[y][x] == EXIT)
			{
				if (!g->coins_num)
					draw_sprite(g->img, g->sprites.door[1], x * 32, y * 32);
				else
					draw_sprite(g->img, g->sprites.door[0], x * 32, y * 32);
			}
		}
	}
	draw_players(g);
}

/*
	Draws the hero and enemies (if they exist), based in their specific coordinates.
*/
static void	draw_players(t_game *game)
{
	int		i;
	int		step;

	i = 0;
	draw_sprite(game->img, game->sprites.hero[game->hero.dir][game->hero.step], \
		game->hero.x, game->hero.y);
	while (i < game->enemies_num)
	{
		step = game->enemies[i].step % 4;
		draw_sprite(game->img, \
			game->sprites.enemy[game->enemies[i].dir][step], \
			game->enemies[i].x, game->enemies[i].y);
		i++;
	}
}

/*
	Receives the image to be drawn and the sprite
	to draw at (x * sprite width, y * sprite height) position of the image.
*/
static void	draw_sprite(t_img *image, t_img *sprite, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < 32)
	{
		i = -1;
		while (++i < 32)
			draw_pixel(image, x + i, y + j, get_color(sprite, i, j));
	}
}

/*
	Draws the color in (x, y) position of the image.
*/
static void	draw_pixel(t_img *img, int x, int y, unsigned int color)
{
	char			*pixel;

	if (color == C_NONE)
		return ;
	pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(unsigned int *)pixel = color;
}

/*
	Returns the pixel color of (x, y) position of the image.
*/
static unsigned int	get_color(t_img *img, int x, int y)
{
	return ((*(unsigned int *)
			(img->data + (x * img->bpp / 8 + y * img->size_line))));
}
