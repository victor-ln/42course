/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:30:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/01 02:51:13 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"

# define ESC 65307
# define MAP "01CEP\n"

# define N_VALID "Invalid map, it must have 1 exit, 1 player and collects"
# define N_SURROUNDED "Invalid map, it's not surrounded by walls"
# define INVALID_CHAR "Invalid map, it has an invalid character or none"
# define N_RECTANGLE "Invalid map, it's not a rectangle"

typedef struct s_sprites
{
	t_img	*ground;
	t_img	*wall;
	t_img	*player;
	t_img	*way_out;
	t_img	*collectible;
}				t_sprites;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			area;
	int			height;
	int			width;
	int			collects;
	int			exits;
	int			player_p;
	int			moved_nbr;
	char		*map;
	t_img		*image;
	t_sprites	sprites;
}				t_game;

#endif
