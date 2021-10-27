/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_data.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 04:00:10 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/27 15:59:19 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_DATA_H
# define SO_LONG_DATA_H

# include <errno.h>
# include <threads.h>
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
# define COLL			19
# define EXIT			21

typedef struct s_sprites
{
	t_img		*grass;
	t_img		*tree;
	t_img		**door;
	t_img		**coins;
	t_img		**arrow;
	t_img		**enemy_death;
	t_img		***hero;
	t_img		***treant;
	t_img		***mole;
}	t_sprites;

typedef struct s_enemies
{
	short		to_x;
	short		to_y;
	short		steps;
	short		step;
	short		dir;
	short		x;
	short		y;
	short		who;
	short		is_alive;
}	t_enemies;

typedef struct s_hero
{
	short		step;
	short		dir;
	short		x;
	short		y;
}	t_hero;

typedef struct s_coord
{
	short		x;
	short		y;
	short		dir;
	short		to_x;
	short		to_y;
}	t_coord;

typedef struct s_game
{
	short		enemies_num;
	short		kills;
	short		coins_num;
	short		height;
	short		width;
	short		frame;
	short		door;
	u_int32_t	moves_num;
	void		*mlx;
	void		*screen;
	char		*moves_str;
	char		**map;
	char		*map_ber;
	t_img		*img;
	t_enemies	*enemies;
	t_sprites	sprites;
	t_hero		hero;
	t_coord		*arrow;
	short		arrows_num;
}	t_game;

#endif
