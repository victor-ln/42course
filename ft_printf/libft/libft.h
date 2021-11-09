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
# include <stdio.h>
# include <unistd.h>

int				ft_toupper(int c);
int				ft_isdigit(int c);
int				ft_strcmp(char *s1, char *s2);
char			*ft_itoa(int n);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *str, int lt);
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
void			ft_bzero(void *ptr, size_t n);

#endif /* LIBFT_H */