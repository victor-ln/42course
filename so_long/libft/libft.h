/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:21:22 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/08 04:21:22 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

/*
** Returns a pointer to the first occurrence of the character c
** in the string src or NULL if the character is not found.
*/
char	*ft_strchr(const char *src, int c);
void	ft_bzero(void *ptr, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
/*
** Converts unsigned numbers into a string.
*/
char	*ft_utoa(unsigned int nbr);
/*
** Compares the two strings and returns the difference
** between them or zero if they're equal.
*/
int		ft_strcmp(char *s1, char *s2);

#endif
