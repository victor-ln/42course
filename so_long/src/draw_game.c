/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:20:03 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/20 00:04:01 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void			draw_sprite(t_img *image, t_img *sprite, int x, int y);
static void			draw_pixel(t_img *image, int x, int y, unsigned int color);
static unsigned int	get_color(t_img *image, int x, int y);
static void			draw_players(t_game *game);

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

	i = -1;
	draw_sprite(game->img, game->sprites.hero[game->hero.dir][game->hero.step], \
		game->hero.x, game->hero.y);
	while (++i < game->enemies_num)
		draw_sprite(game->img, \
			game->sprites.enemy[game->enemies[i].dir][game->enemies[i].step], \
			game->enemies[i].x, game->enemies[i].y);
}

/*
	Receives the image to be drawn and the sprite
	to draw at (x * sprite width, y * sprite height) position of the image.
*/
void	draw_sprite(t_img *image, t_img *sprite, int x, int y)
{
	int		i;
	int		j;

	j = -1;
	while (++j < sprite->height)
	{
		i = -1;
		while (++i < sprite->width)
			draw_pixel(image, x + i, y + j, get_color(sprite, i, j));
	}
}

/*
	Draws the color in (x, y) position of the image.
*/
void	draw_pixel(t_img *img, int x, int y, unsigned int color)
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
unsigned int	get_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}
