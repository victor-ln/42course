/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 00:14:39 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/24 00:14:39 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img	*which_one(char map_point, t_sprites *sprites);

void	render(t_game *g)
{
	int		x;
	int		y;
	int		map_p;

	y = -1;
	while (++y < g->map.height)
	{
		x = -1;
		while (++x < g->map.width)
		{
			map_p = g->map.content[g->map.width * y + x + (y != 0)];
			draw_img(g->image, which_one(map_p, &g->sprites), x, y);
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->image, 0, 0);
	mlx_string_put(g->mlx, g->win, 0, 0, g->moved_nbr * x, "Moved : 0");
}

void	draw_img(t_img *img, t_img *sprite, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	x *= 64;
	y *= 64;
	while (++i < sprite->width)
	{
		j = -1;
		while (++j < sprite->height)
			draw_pixel(img, i + x, j + y, get_color(sprite, i, j));
	}
}

/*
** Controls what sprite to draw.
*/
static t_img	*which_one(char map_point, t_sprites *sprites)
{
	if (map_point == '0')
		return (sprites->ground);
	if (map_point == '1')
		return (sprites->wall);
	if (map_point == 'C')
		return (sprites->collect);
	if (map_point == 'P')
		return (sprites->player);
	return (sprites->way_out);
}

size_t	get_color(t_img *img, int x, int y)
{
	return (*(size_t *) img->data + (y * img->size_line + x * (img->bpp / 8)));
}

void	draw_pixel(t_img *img, int x, int y, size_t color)
{
	char	*pixel;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(size_t *)pixel = color;
}
