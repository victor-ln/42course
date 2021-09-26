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

static void			draw_img(t_img *img, int x, int y);
static void			draw_pixel(t_img *img, int x, int y, unsigned int color);
static unsigned int	which_color(t_img *img, int x, int y);
static t_img		*which_one(char map_point, t_sprites *sprites);

void	render(t_game *g)
{
	int	x;
	int	y;

	x = -1;
	while (++x <= g->map.x)
	{
		y = -1;
		while (++y <= g->map.y)
		{
			if (g->map.map[x + y] == '\n')
				continue ;
			draw_img(which_one(g->map.map[x + y], &g->sprites), x * 64, y * 64);
		}
	}
	g->moved_str = ft_utoa(g->moved_nbr);
	mlx_string_put(g->mlx, g->win, 0, 0, g->moved_nbr * x, "Moved : ");
	mlx_string_put(g->mlx, g->win, 8, 0, g->moved_nbr * x, g->moved_str);
	free(g->moved_str);
	g->moved_str = 0;
}

static void	draw_img(t_img *img, int x, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < img->width)
	{
		j = -1;
		while (++j < img->height)
			draw_pixel(img, i + x, j + y, which_color(img, i, j));
	}
}

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
	return (sprites->exit);
}

static unsigned int	which_color(t_img *img, int x, int y)
{
	return (*(unsigned int *)
		img->data + (y * img->size_line + x * (img->bpp / 8)));
}

static void	draw_pixel(t_img *img, int x, int y, unsigned int color)
{
	char	*pixel;

	pixel = img->data + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}
