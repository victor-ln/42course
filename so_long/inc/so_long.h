/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 19:11:27 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/16 19:11:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "mlx.h"
# include "mlx_int.h"

# define ESC 65307
# define MAP "01CEP\n"

# define PATH_P "./img/player.xpm"
# define PATH_E "./img/gas.xpm"
# define PATH_C "./img/wall.xpm"
# define PATH_0 "./img/sand.xpm"
# define PATH_1 "./img/helicopter.xpm"

typedef struct	s_sprites
{
	t_img	*collect;
	t_img	*player;
	t_img	*ground;
	t_img	*exit;
	t_img	*wall;
}				t_sprites;

typedef struct	s_map
{
	char	*content;
	int		player_p;
	int		player;
	int		collects;
	int		exit;
	int		area;
	int		height;
}				t_map;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	char		*moved_str;
	int			moved_nbr;
	t_map		map;
	t_sprites	sprites;
}				t_game;

char			*load_map(char *filename);
void			start_game(t_game *s_game);
void			init_struct(t_game *s_game);
void			render(t_game *s_game);
int				exit_game(char *message, int status, t_game *s_game);
void			draw_img(t_img *img, int x, int y);
unsigned int	get_color(t_img *img, int x, int y);
void			draw_pixel(t_img *img, int x, int y, unsigned int color);
char			*ft_strchr(const char *src, int c);
char			*ft_utoa(size_t nbr);
int				ft_strcmp(char *s1, char *s2);

#endif // SO_LONG_H