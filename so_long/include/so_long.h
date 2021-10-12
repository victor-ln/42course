/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:15:55 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/12 02:30:01 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_data.h"

/*
	Checks if there's just one argument to be read,
	Opens the file, checks file extension and file descriptor
	and returns the file descriptor or -1 if there is an error.
*/
int				check_input(int argc, char *argv);

/*
	Saves the content of the file specified by the fd in the map pointer or
	exits the game appropriately in case of errors.
*/
void			load_map(t_game *game, int fd);

/*
	Saves map info, such as area, height, width, player position, the number
	of coins, exits and players and checks if they're valid.
*/
void			validate_map(t_game *game);

/*
	Writes the message passed, frees the map pointer 
	and exits the game with status 1.
*/
void			exit_game(t_game *game, char *message);

/*
	Renders pixel per pixel each map point with their respectives sprites.
*/
void			render_game(t_game *game);

/*
	Exits the game if close_window box is clicked.
*/
int				close_window(int keycode, t_game *game);

/*
	Controls where to move when keycode is a, s, d or w
	or exits the game if ESC is pressed.
*/
int				key_press(int keycode, t_game *game);

/*
	Displays the map, the player and the number of movements done
	on the screen.
*/
void			display_game(t_game *game, t_img *character, int x, int y);

/*
	Writes "Error" and the messages passed, frees
	all allocated memory and exits with status 1.
*/
void			error(t_game *game, char *message, char *str_error);

/*
	Returns the pixel color of (x, y) position of the image.
*/
unsigned int	get_color(t_img *image, int x, int y);

/*
	Draws the color in (x, y) position of the image.
*/
void			draw_pixel(t_img *image, int x, int y, unsigned int color);

/*
	Receives the image to be drawn and the sprite
	to draw at (x * sprite width, y * sprite height) position of the image.
*/
void			draw_sprite(t_img *image, t_img *sprite, int x, int y);

/*
	Initializes variables of game structure.
*/
void			init_structure(t_game *game);

/*
	Initializes mlx, opens a window, creates an image and loads all sprites.
	Exits the game appropriately if any error occurs.
*/
void			load_environment(t_game *game);

/*
	Loads a xpm file located in path to the image address pointer passed.
*/
int				each_sprite(t_img **img, void *mlx, char *path);

void			map_validation(t_game *game);

void			map_dimension(t_game *game);

void			map_matrix(t_game *game);

unsigned int	my_rand(void);

#endif
