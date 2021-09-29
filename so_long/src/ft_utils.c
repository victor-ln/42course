/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:23:48 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/29 00:23:48 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_struct(t_game *game)
{
	game->sprites = (t_sprites *)malloc(sizeof(t_sprites));
	game->map.collects = 0;
	game->map.content = 0;
	game->map.height = 1;
	game->map.area = 1;
	game->moved_nbr = 0;
	game->image = 0;
	game->mlx = 0;
	game->win = 0;
	game->sprites->collect = 0;
	game->sprites->ground = 0;
	game->sprites->player = 0;
	game->sprites->wall = 0;
	game->sprites->way_out = 0;
}

int	is_end_after_c(char *s, char c, char end)
{
	while (*s == c)
		s++;
	return (*s != end);
}
