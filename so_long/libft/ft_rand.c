/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:11:35 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/10/18 15:11:47 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_rand(void)
{
	static unsigned int		lfsr;
	unsigned int			bit;

	if (!lfsr)
		lfsr = 0XFABC;
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	lfsr = (lfsr >> 1) | (bit << 15);
	return (lfsr);
}