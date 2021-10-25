/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:20:03 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/25 12:47:30 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void			draw_players(t_game *game);
static void			draw_sprite(t_img *image, t_img *sprite, int x, int y);
static void			draw_pixel(t_img *image, int x, int y, unsigned int color);
static unsigned int	get_color(t_img *image, int x, int y);

void	draw_game(t_game *game)
{
	register int		x;
	register int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_sprite(game->img, game->sprites.grass, x * 32, y * 32);
			if (game->map[y][x] == 1)
				draw_sprite(game->img, game->sprites.tree, x * 32, y * 32);
			else if (game->map[y][x] == COLL)
				draw_sprite(game->img, game->sprites.coins[game->frame / 2], \
					x * 32, y * 32);
			else if (game->map[y][x] == EXIT)
				draw_sprite(game->img, game->sprites.door[game->door], \
					x * 32, y * 32);
			x++;
		}
		y++;
	}
	draw_players(game);
}

/*
	Draws the hero and enemies (if they exist), based in their specific coordinates.
*/
static void	draw_players(t_game *game)
{
	register int		i;

	i = 0;
	draw_sprite(game->img, \
		game->sprites.hero[game->hero.dir][game->hero.step], \
		game->hero.x, game->hero.y);
	while (i < game->enemies_num)
	{
		draw_sprite(game->img, \
			game->sprites.enemy[game->enemies[i].dir][game->enemies[i].step], \
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
	register int		i;
	register int		j;

	j = 0;
	while (j < 32)
	{
		i = 0;
		while (i < 32)
		{
			draw_pixel(image, x + i, y + j, get_color(sprite, i, j));
			i++;
		}
		j++;
	}
}

/*
	Draws the color in (x, y) position of the image.
*/
static void	draw_pixel(t_img *img, int x, int y, unsigned int color)
{
	if (color != C_NONE)
		*(unsigned int *)
			((img->data + (x * img->bpp / 8 + y * img->size_line))) = color;
}

/*
	Returns the pixel color of (x, y) position of the image.
*/
static unsigned int	get_color(t_img *img, int x, int y)
{
	return ((*(unsigned int *)
			(img->data + (x * img->bpp / 8 + y * img->size_line))));
}
