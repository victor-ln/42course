/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:46:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/01 04:20:05 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*which_sprite(char map_point, t_sprites *sprites);
static void		draw_sprite(t_img *img, t_img *sprite, int x, int y);
static void		draw_pixel(t_img *img, int x, int y, size_t color);
static size_t	get_color(t_img *img, int x, int y);

void	render_game(t_game *game)
{
	int		x;
	int		y;
	int		map_p;
	char	*temp;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			map_p = game->map[game->width * y + x + (y != 0)];
			draw_sprite(game->image, which_sprite(map_p, &game->sprites), x, y);
			x++;
		}
		y++;
	}
	temp = ft_utoa(game->moved_nbr);
	if (!temp)
		exit_game(game, "Malloc for moves string failed\n", 2);
	mlx_put_image_to_window(game->mlx, game->win, game->image, 0, 0);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, "Moved :");
	mlx_string_put(game->mlx, game->win, 60, 10, 0xFFFFFF, temp);
	free(temp);
	temp = 0;
}

/*
** Receives the image to be drawn and the sprite
** to draw at (x * image_width) (y * image_height) position of the image.
*/
static void	draw_sprite(t_img *img, t_img *sprite, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	x *= 32;
	y *= 32;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			draw_pixel(img, i + x, j + y, get_color(sprite, i, j));
			j++;
		}
		i++;
	}
}

/*
** Controls which sprite to draw.
*/
static t_img	*which_sprite(char map_point, t_sprites *sprites)
{
	if (map_point == '0')
		return (sprites->ground);
	if (map_point == '1')
		return (sprites->wall);
	if (map_point == 'C')
		return (sprites->collectible);
	if (map_point == 'P')
		return (sprites->player);
	return (sprites->way_out);
}

/*
** Returns the pixel color of (x, y) position of the sprite.
*/
static size_t	get_color(t_img *img, int x, int y)
{
	return (((size_t *)img->data)[y * img->size_line + x * (img->bpp / 8)]);
}

/*
** Draws the color in (x, y) position of the image.
*/
static void	draw_pixel(t_img *img, int x, int y, size_t color)
{
	img->data[y * img->size_line + x * (img->bpp / 8)] = color;
}
