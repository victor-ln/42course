/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 00:45:00 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/07 00:45:24 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Compares both strings s1 and s2 and returns the difference
** between them or zero if they're equal.
*/
int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
