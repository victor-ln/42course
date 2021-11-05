/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:02:17 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/05 01:26:36 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_getting_signal = 0;

static void	get_signal(int signal);
static void	print_bits(char *bits);
static void	error(char *message);

int	main(void)
{
	int		pid;

	pid = getpid();
	if (pid < 0)
		error("Could not get pid");
	ft_printf("%d", pid);
	while (1)
	{
		signal(SIGUSR1, get_signal);
		signal(SIGUSR2, get_signal);
		if (!g_getting_signal)
			pause();
	}
}

static void	get_signal(int signal)
{
	static int	counter;
	static char	bits[7];

	if (!counter)
	{
		counter = 7;
		g_getting_signal = 1;
	}
	bits[--counter] = (signal == SIGUSR2);
	if (!counter)
		print_bits(bits);
}

static void	print_bits(char *bits)
{
	int		i;
	int		ch;

	ch = 0;
	i = 0;
	while (i < 7)
	{
		ch *= 2;
		if (bits[i])
			ch++;
		i++;
	}
	write(1, &ch, 1);
	g_getting_signal = 0;
}

static void	error(char *message)
{
	write(2, "Error\n", 6);
	while (*message)
		write(2, message++, 1);
	write(2, "\n", 1);
	exit(1);
}
