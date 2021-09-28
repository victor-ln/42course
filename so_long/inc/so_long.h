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
** Opens the file, checks file extension and file descriptor.
** Returns the content in the file saved in a char pointer or
** exits the program in case of errors.
*/
char	*load_map(char *filename);
/*
** Initializes stack variables of game structure and its sub structures.
*/
void	init_struct(t_game *game);
/*
** Saves map data, such as area, height, width, player position, the number
** of collects, exits and players. Opens a window and gets sprites from ./img
*/
void	start_game(t_game *game);
/*
** Renders pixel per pixel each map point with their respectives sprites.
*/
void	render(t_game *game);
/*
** Writes "Error" if status is equals to 1, writes the message passed,
** free all allocated memory and exits with status as argument.
*/
void	exit_game(char *message, int status, t_game *game);
/*
** Receives the image to be drawn and the sprite
** to draw at (x * 64) (y * 64) position of the image.
*/
void	draw_img(t_img *img, t_img *sprite, int x, int y);
/*
** Returns the pixel color of (x, y) position of the sprite.
*/
size_t	get_color(t_img *img, int x, int y);
/*
** Draws the color in (x, y) position of the image.
*/
void	draw_pixel(t_img *img, int x, int y, size_t color);
/*
** Returns a pointer to the first occurrence of the character c
** in the string src or NULL if the character is not found.
*/
char	*ft_strchr(const char *src, int c);
/*
** Converts unsigned numbers into a string.
*/
char	*ft_utoa(size_t nbr);
/*
** Compares the two strings and returns the difference
** between them or zero if they're equal.
*/
int		ft_strcmp(char *s1, char *s2);
/*
** Runs the string till c differs *s.
** If after it differs *s is equals to limit returns 0 else returns 1.
*/
int		is_limit_after_c(char *s, int c, int limit);

#endif
