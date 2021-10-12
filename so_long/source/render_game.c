/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:46:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 02:32:22 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_game(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 1)
				draw_sprite(game->img, game->sprites->tree, x * 32, y * 32);
			else
				draw_sprite(game->img, game->sprites->grass, x * 32, y * 32);
			x++;
		}
		y++;
	}
	draw_sprite(game->img, game->sprites->door_c, game->exit.x, game->exit.y);
	x = game->hero.x;
	y = game->hero.y;
	if (x <= game->width / 2)
		display_game(game, game->sprites->hero[RIGHT]->idle, x, y);
	else
		display_game(game, game->sprites->hero[LEFT]->idle, x, y);
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

	pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(unsigned int *)pixel = color;
}
