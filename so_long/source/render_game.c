/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:46:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:25:15 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_coins(t_img **images, t_img **sprites, int x, int y);

void	draw_game(t_game *g)
{
	int		x;
	int		y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			draw_sprite(g->map_img, g->sprites.grass, x * 32, y * 32);
			if (g->map[y][x] == 1)
				draw_sprite(g->map_img, g->sprites.tree, x * 32, y * 32);
			if (g->map[y][x] == COLL)
				draw_coins(g->coins_img, g->sprites.coins, x * 32, y * 32);
			else
				erase_coins(g->coins_img, x * 32, y * 32);
			x++;
		}
		y++;
	}
	draw_sprite(g->map_img, g->sprites.door_c, g->exit.x, g->exit.y);
}

static void	draw_coins(t_img **images, t_img **sprites, int x, int y)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		draw_sprite(images[i], sprites[i], x, y);
		i++;
	}
}

void	draw_sprite(t_img *image, t_img *sprite, int x, int y)
{
	int		i;
	int		j;

	j = 0;
	while (j < sprite->height)
	{
		i = 0;
		while (i < sprite->width)
		{
			draw_pixel(image, x + i, y + j, get_color(sprite, i, j));
			i++;
		}
		j++;
	}
}

void	erase_coins(t_img **image, int x, int y)
{
	int		fixed[2];
	int		height;
	int		width;
	int		i;

	fixed[0] = x;
	fixed[1] = y;
	width = x + 32;
	height = y + 32;
	i = 0;
	while (++i < 4)
	{
		y = fixed[1];
		while (y < height)
		{
			x = fixed[0];
			while (x < width)
			{
				draw_pixel(image[i], x, y, 0xFF000000);
				x++;
			}
			y++;
		}
		i++;
	}
}
