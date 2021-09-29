/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 23:51:00 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/27 23:51:00 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

# define ESC 65307
# define MAP "01CEP\n"

# define N_VALID "Invalid map, there must have 1 exit, 1 player and collects\n"
# define N_RECTANGLE "Invalid map, its not a rectangle\n"
# define SQUARE "Invalid map, it's a square. It must be a rectangle\n"
# define N_SURROUNDED "Invalid map, it's not surrounded by walls\n"
# define INVALID_CHAR "Invalid map, it has an invalid character\n"
# define N_ENOUGH_L "Invalid map, not enough lines or columns\n"

typedef struct s_sprites
{
	t_img	*collect;
	t_img	*player;
	t_img	*ground;
	t_img	*way_out;
	t_img	*wall;
}				t_sprites;

typedef struct s_map
{
	int		area;
	int		height;
	int		width;
	int		collects;
	int		player_p;
}				t_map;

typedef struct s_game
{
	char		*map;
	void		*mlx;
	void		*win;
	int			moved_nbr;
	t_img		*image;
	t_sprites	*sprites;
	t_map		map_info;
}				t_game;

#endif
