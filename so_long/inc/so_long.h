/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:15:55 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 17:55:00 by vlima-nu         ###   ########.fr       */
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
	Writes the message passed, frees the map pointer 
	and exits the game with status 1.
*/
void			exit_game(t_game *game, char *message);

/*
	Renders pixel per pixel each map point with their respectives sprites.
*/
void			draw_game(t_game *game);

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
void			display_game(t_game *game);

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
void			struct_init(t_game *game);

/*
	Initializes display, opens a window, creates an image and loads all sprites.
	Exits the game appropriately if any error occurs.
*/
void			load_environment(t_game *game);

/*
	Gets map information and creates a matrix of the map.
	Searches in the map free spaces to put enemies and
	gets the coordinates of the player and enemies on the map.
*/
void			map_init(t_game *game);

/*
	Checks if map has at least one player,
	one exit, and collects, if is rectangular and symmetrical,
	if it's surrounded by walls "1"
	and if there's only the "01PEC\n" chars.
*/
void			map_validate(t_game *game);

/*
	Keeps game in loop even without a hook,
	rendering coins and enemies moving.
*/
int				animation(t_game *game);

/*
	Checks if the hero has been caught by an enemy.
*/
void			hero_got_caught(t_game *game);

#endif
