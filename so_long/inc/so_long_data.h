/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:30:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/19 23:01:15 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include <errno.h>
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include "libft.h"

# define C_WHITE		0xFFFFFF
# define C_NONE			0xFF000000
# define ESC			65307
# define UP				0
# define DOWN			1
# define RIGHT			2
# define LEFT			3
# define HERO			32
# define ENEMY			2
# define COLL			67
# define EXIT			69

typedef struct s_sprites
{
	t_img			*grass;
	t_img			*tree;
	t_img			**door;
	t_img			**coins;
	t_img			***hero;
	t_img			***enemy;
}	t_sprites;

typedef struct s_players
{
	short		to_x;
	short		to_y;
	short		step;
	u_int16_t	dir;
	int			x;
	int			y;
}	t_players;

typedef struct s_game
{
	u_int16_t	enemies_num;
	u_int16_t	coins_num;
	u_int16_t	height;
	u_int16_t	width;
	u_int16_t	frame;
	u_int32_t	moves_num;
	void		*mlx;
	void		*screen;
	char		*moves_str;
	char		**map;
	char		*map_ber;
	t_img		*img;
	t_sprites	sprites;
	t_players	hero;
	t_players	*enemies;
}	t_game;

#endif
