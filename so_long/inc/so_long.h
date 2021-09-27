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

# include "so_long_init.h"

/*
** includes all structs, macros and other headers
*/
char	*load_map(char *filename);
/*
** Opens argv, checks file extension and descriptor
** and saves the map or exit the program in case of errors.
*/
void	init_struct(t_game *game);
/*
** Initializes stack variables of game structure and its sub structures.
*/
void	start_game(t_game *game);
/*
** Saves map info, such as area, height, player position, etc,
** Opens a window and get sprites from ./img/xpm
*/
void	render(t_game *game);
/*
** Renders pixel per pixel each map character with this respectives sprites.
*/
int		exit_game(char *message, int status, t_game *game);
/*
** Writes "Error\n" if status equals 1,
** writes the message passed, free all allocated memory and exit(status).
*/
void	draw_img(t_img *img, t_img *sprite, int x, int y);
/*
** Receives the image to be drawn and the sprite
** to draw at ((x * 64),(y * 64)) position of the image.
*/
size_t	get_color(t_img *img, int x, int y);
/*
** Returns the pixel color of (x, y) position of the sprite.
*/
void	draw_pixel(t_img *img, int x, int y, size_t color);
/*
** Draws the color in (x, y) position of the image.
*/
char	*ft_strchr(const char *src, int c);
/*
** Returns a pointer to the first occurrence of the character c
** in the string src or NULL if the character is not found.
*/
char	*ft_utoa(size_t nbr);
/*
** Converts unsigned numbers into a string.
*/
int		ft_strcmp(char *s1, char *s2);
/*
** Compares the two strings and returns the difference
** between then or zero if they're equal.
*/

#endif
