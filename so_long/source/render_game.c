/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:46:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 22:58:40 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void		draw_image(t_game *game, int x, int y, char map_point);

void	render_game(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
			draw_image(game, x, y, game->map[game->width * y + x]);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

/*
** Receives the image to be drawn and the sprite
** to draw at (x * image_width) (y * image_height) position of the image.
*/
static void	draw_image(t_game *game, int x, int y, char map_point)
{
	if (map_point == '0')
		draw_sprite(game->img, game->sprites->ground, x, y);
	else if (map_point == '1')
		draw_sprite(game->img, game->sprites->wall, x, y);
	else if (map_point == 'C')
		draw_sprite(game->img, game->sprites->collectible, x, y);
	else if (map_point == 'E')
		draw_sprite(game->img, game->sprites->way_out, x, y);
	else if (map_point == 'P')
		draw_sprite(game->img, game->sprites->player, x, y);
}

void	draw_sprite(t_img *img, t_img *sprite, int x, int y)
{
	int		i;
	int		j;

	x *= sprite->width;
	y *= sprite->height;
	i = -1;
	while (++i < sprite->height)
	{
		j = -1;
		while (++j < sprite->width)
			draw_pixel(img, i + x, j + y, get_color(sprite, i, j));
	}
}

size_t	get_color(t_img *img, int x, int y)
{
	return (*(size_t *)img->data + (x * img->bpp / 8 + y * img->size_line));
}

void	draw_pixel(t_img *img, int x, int y, size_t color)
{
	char	*pixel;

	pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(size_t *)pixel = color;
}
