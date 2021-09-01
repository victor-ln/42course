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

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

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
	int		width;
	int		precision;
	char	precision_c;
}	t_params;

int		ft_printf(t_data *format, ...);
int		ft_print_args(t_params p, va_list args);
int		ft_is_valid(t_data *format, t_params *p, va_list args);

char	*ft_specifier_c(va_list args);
char	*ft_specifier_p(va_list args);
char	*ft_specifier_s(va_list args, t_params p);
char	*ft_specifier_u(va_list args, t_params p);
char	*ft_specifier_d_or_i(va_list args, t_params params);
char	*ft_specifier_x_or_upper_x(va_list args, t_params p);

char	*ft_utoa(unsigned int nbr);
char	*ft_hextoa(size_t nbr);

void	ft_start_struct(t_params *p);
int		ft_strcmp(char *s1, char *s2);
int		ft_printchar(int width, char c, int len);
t_data	*ft_toward_specifier(t_data *format);

int		ft_print_hash_flag(t_params p, char *arg);
int		ft_print_precision(char *arg, t_params p);
int		ft_print_plus_or_space_flag(char arg, t_params p, int len);
int		ft_print_zeros_or_blank_flag(t_params p, int len, char *arg);

#endif