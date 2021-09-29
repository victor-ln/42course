/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 22:46:56 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/09/27 22:46:56 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// includes all structs, macros and other headers
# include "so_long_data.h"

/*
** Check how many arguments was passed,
** Opens the file, checks file extension and file descriptor.
** Returns the content in the file saved in a char pointer or
** exits the program in case of errors.
*/
char	*ft_load_map(char *filename, int counter);
/*
** Initializes stack variables of game structure and its sub structures.
*/
void	init_struct(t_game *game);
/*
** Saves map info, such as area, height, width, player position, the number
** of collects, exits and players. Opens a window and gets sprites from ./img
*/
void	ft_start_game(t_game *game);
/*
** Renders pixel per pixel each map point with their respectives sprites.
*/
void	ft_render(t_game *game);
/*
** Writes "Error" if status is equals to 1, writes the message passed,
** free all allocated memory and exits with status as argument.
*/
void	exit_game(char *message, int status, t_game *game);
/*
** Receives the image to be drawn and the sprite
** to draw at (x * 64) (y * 64) position of the image.
*/
void	draw_image(t_img *img, t_img *sprite, int x, int y);
/*
** Returns the pixel color of (x, y) position of the sprite.
*/
size_t	get_color(t_img *img, int x, int y);
/*
** Draws the color in (x, y) position of the image.
*/
void	draw_pixel(t_img *img, int x, int y, size_t color);
/*
** Runs the string till c differs *s.
** If after it differs *s is equals to end returns 0 else returns 1.
*/
int		is_end_after_c(char *s, char c, char end);

#endif
