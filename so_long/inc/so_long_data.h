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
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "mlx.h"
# include "mlx_int.h"

# define ESC 65307
# define MAP "01CEP\n"

# define PATH_P "./img/player.xpm"
# define PATH_C "./img/collect.xpm"
# define PATH_E "./img/exit.xpm"
# define PATH_0 "./img/ground.xpm"
# define PATH_1 "./img/wall.xpm"

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
	int		exits;
	int		player;
	int		collects;
	int		player_p;
	char	*content;
}				t_map;

typedef struct s_game
{
	int			moved_nbr;
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		*image;
	t_sprites	sprites;
}				t_game;

#endif
