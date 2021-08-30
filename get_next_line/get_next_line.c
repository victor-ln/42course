/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:29:16 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/08/11 18:29:16 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static ssize_t	ft_check_break_line(const char *string);
static void		ft_save_buffer(char **save, t_get_next_line data);
static char		*ft_rt_last_string(char **save, t_get_next_line data);
static char		*ft_has_break_line(char **save, t_get_next_line data);

char	*get_next_line(int fd)
{
	static char		*save;
	t_get_next_line	data;

	data.size = 1;
	while (data.size > 0)
	{
		data.size = read(fd, data.buffer, BUFFER_SIZE);
		data.buffer[data.size] = 0;
		ft_save_buffer(&save, data);
		if (!data.size && ft_strlen(save) && ft_check_break_line(save) < 0)
			return (ft_rt_last_string(&save, data));
		else if (ft_strlen(save) && (ft_check_break_line(save) >= 0))
			return (ft_has_break_line(&save, data));
	}
	free(save);
	save = 0;
	return (NULL);
}

static void	ft_save_buffer(char **save, t_get_next_line data)
{
	if (!*save && data.size > 0)
		*save = ft_strdup(data.buffer);
	else if (*save && data.size > 0)
	{
		data.temp_str = ft_strdup(*save);
		free(*save);
		*save = ft_strjoin(data.temp_str, data.buffer);
		free(data.temp_str);
	}
}

static ssize_t	ft_check_break_line(const char *string)
{
	ssize_t	i;

	i = 0;
	if (!string)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_rt_last_string(char **save, t_get_next_line data)
{
	data.ret_str = ft_strdup(*save);
	free(*save);
	*save = 0;
	return (data.ret_str);
}

static char	*ft_has_break_line(char **save, t_get_next_line data)
{
	data.str_len = ft_check_break_line(*save) + 1;
	data.ret_str = ft_substr(*save, 0, data.str_len);
	data.temp_str = ft_substr(*save, data.str_len,
			(ft_strlen(*save) + 1 - data.str_len));
	free(*save);
	*save = ft_strdup(data.temp_str);
	free(data.temp_str);
	data.temp_str = 0;
	return (data.ret_str);
}
