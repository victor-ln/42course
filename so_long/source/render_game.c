/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 00:46:12 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 21:39:04 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_game(t_game *game)
{
	int			x;
	int			y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			draw_image(game, x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	move_display(game);
}

void	draw_image(t_game *game, int x, int y)
{
	char	*map_point;

	map_point = game->map[y][x];
	if (map_point == '1')
		draw_sprite(game->img, game->sprites->wall, x, y);
	else if (map_point == '0')
		draw_sprite(game->img, game->sprites->ground, x, y);
	else if (map_point == 'C')
		draw_sprite(game->img, game->sprites->collect, x, y);
	else if (map_point == 'E')
		draw_sprite(game->img, game->sprites->way_out, x, y);
	else if (game->player.x <= (game->width / 2))
		draw_sprite(game->img, game->sprites->player_d[RIGHT]->moves[3], x, y);
	else
		draw_sprite(game->img, game->sprites->player_d[LEFT]->moves[3], x, y);
}

void	draw_sprite(t_img *image, t_img *sprite, int x, int y)
{
	int			i;
	int			j;

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

	if (color != WHITE)
	{
		pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
		*(unsigned int *)pixel = color;
	}
}
