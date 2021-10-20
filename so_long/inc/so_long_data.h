/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:30:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/19 22:17:16 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include <errno.h>
# include "mlx.h"
# include "mlx_int.h"
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
	int			exits_num;
	int			heros_num;
	int			coins_num;
	int			enemies_num;
	u_int32_t	moves_num;
	int			width;
	int			height;
	short		frame;
	void		*mlx;
	void		*screen;
	char		*moves_str;
	t_players	*enemies;
	t_img		*img;
	char		**map;
	char		*map_ber;
	t_sprites	sprites;
	t_players	hero;
}	t_game;

#endif
