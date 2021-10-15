/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:30:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 23:48:14 by vlima-nu         ###   ########.fr       */
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

# define MAP			"01CEP\n"

# define ESC			65307

# define UP				0
# define DOWN			1
# define RIGHT			2
# define LEFT			3

# define HERO			32
# define ENEMY			2
# define COLL			19
# define EXIT			21

typedef struct s_moves
{
	t_img		**walk;
	t_img		*idle;
}	t_moves;

typedef struct s_sprites
{
	t_img			*grass;
	t_img			*tree;
	t_img			*door_o;
	t_img			*door_c;
	t_img			**coins;
	t_moves			**hero;
	t_moves			**enemy;
}	t_sprites;

typedef struct s_coord
{
	int			x;
	int			y;
}	t_coord;

typedef struct s_enemies
{
	int			x;
	int			y;
	int			moved_to;
	int			step;
}	t_enemies;

typedef struct s_game
{
	char		**map;
	void		*display;
	void		*screen;
	int			exits;
	int			heros;
	int			width;
	int			height;
	int			coins_n;
	int			moved_to;
	int			enemies_n;
	size_t		moves;
	char		*moves_str;
	char		*map_b;
	t_sprites	sprites;
	t_coord		hero;
	t_coord		exit;
	t_coord		*coins;
	t_enemies	*enemies;
	t_img		*map_img;
	t_img		**coins_img;
}	t_game;

#endif
