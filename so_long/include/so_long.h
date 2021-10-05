/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 01:29:15 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/04 19:49:12 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "so_long_data.h"

/*
** Checks if there's just one argument to be read,
** Opens the file, checks file extension and file descriptor and
** Saves the content of argv file in the map char pointer or
** exits the game in case of errors.
*/
void	load_map(t_game *game, int argc, char *argv);

/*
** Calls the key functions of the game.
*/
void	start_game(t_game *game);

/*
** Saves map info, such as area, height, width, player position, the number
** of collects, exits and players and checks if they're valid.
*/
void	validate_map(t_game *game);

/*
** Writes the message passed, frees the map pointer 
** and exits the game with status 1.
*/
void	exit_game(t_game *game, char *message);

/*
** Renders pixel per pixel each map point with their respectives sprites.
*/
void	render_game(t_game *game);

/*
** Exits the game if close_window box is clicked.
*/
int		close_window(int keycode, t_game *game);

/*
** Controls where to move when keycode is a, s, d or w
** or exits the game if ESC is pressed.
*/
int		key_press(int keycode, t_game *game);

/*
** Returns a pointer to the first occurrence of the character c
** in the string src or NULL if the character is not found.
*/
char	*ft_strchr(const char *src, int c);

/*
** Converts unsigned numbers into a string.
*/
char	*ft_utoa(unsigned int nbr);

/*
** Compares the two strings and returns the difference
** between them or zero if they're equal.
*/
int		ft_strcmp(char *s1, char *s2);

/*
** Allocates the length of the sum both strings into a new pointer and returns
** it with first string copied and the second concatenated.
*/
char	*ft_strjoin(const char *s1, const char *s2);

/*
** Returns how many characters are in the passed string.
*/
size_t	ft_strlen(const char *str);

/*
** Writes the string passed to the fd passed.
*/
void	ft_putstr_fd(char *s, int fd);

/*
**
*/
void	move_display(t_game *game);

void	error(t_game *game, char *message, int error);

/*
** Returns the pixel color of (x, y) position of the sprite.
*/
size_t	get_color(t_img *img, int x, int y);

/*
** Draws the color in (x, y) position of the image.
*/
void	draw_pixel(t_img *img, int x, int y, size_t color);

/*
** Controls which sprite to draw.
*/
void	draw_sprite(t_img *img, t_img *sprite, int x, int y);

#endif
