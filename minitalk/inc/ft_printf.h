/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:15:39 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/16 20:15:39 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define LIMIT 2147483614
# define TYPES "cspdiuxX%"
# define FLAGS "# +0-"

typedef const char	t_data;

typedef struct s_params
{
	char	type;
	char	hash;
	char	plus_or_space;
	char	zr_or_spaces;
	char	precision_c;
	int		precision;
	int		width;
}	t_params;

int		ft_printf(const char *format, ...);
int		print_args(t_params params, va_list args);
int		is_valid(t_data *format, t_params *p, va_list args);

char	*specifier_c(va_list args);
char	*specifier_p(va_list args);
char	*specifier_s(va_list args, t_params params);
char	*specifier_u(va_list args, t_params params);
char	*specifier_d_or_i(va_list args, t_params params);
char	*specifier_x_or_upper_x(va_list args, t_params params);

char	*ft_utoa(unsigned int nbr);
char	*ft_hextoa(size_t nbr);

int		ft_strcmp(char *s1, char *s2);
int		printchar(int width, char c, int offset);
t_data	*toward_specifier(t_data *format);

int		print_hash_flag(t_params params, char *arg);
int		print_precision(char *arg, t_params params);
int		print_plus_or_space_flag(char arg, t_params params, int len);
int		print_zeros_or_blank_flag(t_params params, int len, char *arg);

#endif