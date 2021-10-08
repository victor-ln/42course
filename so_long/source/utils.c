/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 20:30:31 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/08 02:16:15 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(void **ptr, size_t len)
{
	size_t	i;

	i = 0;
	if (ptr != 0)
	{
		while (i < len)
		{
			if (ptr[i] != 0)
				free(ptr[i]);
			ptr[i] = 0;
			i++;
		}
		free(ptr);
		ptr = 0;
	}
}

void	**malloc_matrix(size_t n_bytes, size_t len)
{
	void	**ptr;
	size_t	i;

	i = 0;
	ptr = malloc(len);
	if (!ptr)
		return (NULL);
	if (n_bytes)
	{
		while (i < len)
		{
			ptr[i] = malloc(n_bytes);
			if (!ptr[i])
			{
				free_matrix(ptr, i);
				return (NULL);
			}
			i++;
		}
	}
	return (ptr);
}
