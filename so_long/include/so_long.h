/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:15:55 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/14 23:49:13 by vlima-nu         ###   ########.fr       */
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
int			check_input(int argc, char *argv);

/*
	Saves the content of the file specified by the fd in the map pointer or
	exits the game appropriately in case of errors.
*/
void		load_map(t_game *game, int fd);

/*
	Saves map info, such as the number
	of coins, exits and players and checks if the map configuration is valid.
*/
void		validate_map(t_game *game);

/*
	Writes the message passed, frees the map pointer 
	and exits the game with status 1.
*/
void		exit_game(t_game *game, char *message);

/*
	Renders pixel per pixel each map point with their respectives sprites.
*/
void		draw_game(t_game *game);

/*
	Exits the game if close_window box is clicked.
*/
int			close_window(int keycode, t_game *game);

/*
	Controls where to move when keycode is a, s, d or w
	or exits the game if ESC is pressed.
*/
int			key_press(int keycode, t_game *game);

/*
	Displays the map, the player and the number of movements done
	on the screen.
*/
void		display_game(t_game *g, int step);

/*
	Writes "Error" and the messages passed, frees
	all allocated memory and exits with status 1.
*/
void		error(t_game *game, char *message, char *str_error);

/*
	Returns the pixel color of (x, y) position of the image.
*/
u_int32_t	get_color(t_img *image, int x, int y);

/*
	Draws the color in (x, y) position of the image.
*/
void		draw_pixel(t_img *image, int x, int y, u_int32_t color);

/*
	Receives the image to be drawn and the sprite
	to draw at (x * sprite width, y * sprite height) position of the image.
*/
void		draw_sprite(t_img *image, t_img *sprite, int x, int y);

/*
	Initializes variables of game structure.
*/
void		struct_init(t_game *game);

/*
	Initializes display, opens a window, creates an image and loads all sprites.
	Exits the game appropriately if any error occurs.
*/
void		load_environment(t_game *game);

/*
	Loads a xpm file located in path to the image address pointer passed.
*/
int			each_sprite(t_img **img, void *display, char *path);

void		map_init(t_game *game);

/*
	Checks if map has at least one player,
	one exit, and collects.
	Also checks if it's surrounded by walls "1"
	and if there's only the "01PEC\n" chars.
*/
void		map_validation(t_game *game);

/*
	Calculates the width and the height of the map and then
	checks if the map is symmetrical and rectangular.
*/
void		map_dimension(t_game *game);

/*
	Generates unsigned random numbers.
*/
u_int32_t		my_rand(void);

int			animation(t_game *game);

void		is_game_over(t_game *game);

void		move_controller(t_game *game, u_int32_t direction);

void		erase_coins(t_img **image, int x, int y);

#endif
