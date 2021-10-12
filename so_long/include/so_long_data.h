/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:30:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 11:14:08 by vlima-nu         ###   ########.fr       */
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

# define ESC			65307

# define UP				0
# define DOWN			1
# define RIGHT			2
# define LEFT			3

typedef struct s_moves
{
	t_img		**walk;
	t_img		*idle;
}				t_moves;

typedef struct s_sprites
{
	t_img			*grass;
	t_img			*tree;
	t_img			*door_o;
	t_img			*door_c;
	t_img			**coins;
	t_moves			**hero;
	t_moves			**enemy;
}				t_sprites;

typedef struct s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct s_game
{
	char		**map;
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			exits;
	int			heros;
	int			coins_n;
	int			movements;
	int			stopped[2];
	int			walls;
	t_img		*img;
	t_sprites	*sprites;
	char		*map_b;
	t_coord		hero;
	t_coord		exit;
	t_coord		enemy;
	t_coord		*coins;
}				t_game;

#endif
