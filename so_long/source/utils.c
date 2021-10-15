/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 00:35:56 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 22:48:31 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

u_int32_t	my_rand(void)
{
	static u_int16_t	lfsr;
	u_int32_t			bit;

	if (!lfsr)
		lfsr = 0XFABC;
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	lfsr = (lfsr >> 1) | (bit << 15);
	return (lfsr);
}

void	is_game_over(t_game *game)
{
	int		i;

	i = -1;
	while (++i < game->enemies_n)
		if (game->hero.x == game->enemies[i].x && \
			game->hero.y == game->enemies[i].y)
			exit_game(game, "GAME OVER\nYOU LOSE");
}

u_int32_t	get_color(t_img *img, int x, int y)
{
	return (*(u_int32_t *)
		(img->data + (x * img->bpp / 8 + y * img->size_line)));
}

void	draw_pixel(t_img *img, int x, int y, u_int32_t color)
{
	char			*pixel;

	pixel = img->data + (x * img->bpp / 8 + y * img->size_line);
	*(u_int32_t *)pixel = color;
}
