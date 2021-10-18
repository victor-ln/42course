/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:20:03 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 17:48:13 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_controller(t_game *g, int x, int y, char map_point);

void	draw_game(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_controller(game, x * 32, y * 32, game->map[y][x]);
			x++;
		}
		y++;
	}
}

static void	draw_controller(t_game *g, int x, int y, char map_point)
{
	draw_sprite(g->img, g->sprites.grass, x, y);
	if (map_point == 1)
		draw_sprite(g->img, g->sprites.tree, x, y);
	else if (map_point == COLL)
		draw_sprite(g->img, g->sprites.coins[g->frame], x, y);
	else if (map_point == EXIT)
	{
		if (!g->coins_num)
			draw_sprite(g->img, g->sprites.door[1], x, y);
		else
			draw_sprite(g->img, g->sprites.door[0], x, y);
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

unsigned int	get_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	draw_pixel(t_img *img, int x, int y, unsigned int color)
{
	char			*pixel;

	if (color == C_NONE)
		return ;
	pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(unsigned int *)pixel = color;
}
