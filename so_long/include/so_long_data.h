/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:30:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 22:44:55 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

# define INVALID		"Invalid map, must have 1 exit, 1 player and collects\n"
# define N_SURROUNDED	"Invalid map, it's not surrounded by walls\n"
# define INVALID_CHAR	"Invalid map, it has an invalid character\n"
# define N_RECTANGLE	"Invalid map, it's not rectangular\n"
# define N_SYMMETRIC	"Invalid map, it's not symmetrical\n"
# define EMPTY			"Invalid map, it is empty\n"
# define MAP			"01CEP\n"
# define WHITE			0XFFFFFF
# define ESC			65307
# define UP				0
# define DOWN			1
# define RIGHT			2
# define LEFT			3

typedef struct s_player
{
	t_img		**moves;
}			t_player;

typedef struct s_sprites
{
	t_img		*ground;
	t_img		*wall;
	t_img		*way_out;
	t_img		*collect;
	t_player	**player_d;
}				t_sprites;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_game
{
	char		**map;
	char		*map_b;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			exit_p;
	int			player_p;
	int			collects;
	int			movements;
	t_img		*img;
	t_sprites	*sprites;
	t_coord		player;
	t_coord		exit;
}				t_game;

#endif
