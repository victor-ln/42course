/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:47:14 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/11 03:14:22 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	g_client;

#define INV_ARGC "Invalid number of arguments\n\
it needs the server PID and a message to send"

int	main(int argc, char **argv)
{
	t_sigaction	sa;

	ft_bzero(&sa, sizeof(t_sigaction));
	if (argc != 3)
		error(INV_ARGC, "CLIENT");
	start_struct(argv);
	sa.sa_handler = get_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	connect();
	while (g_client.is_connected && !kill(g_client.server_pid, 0))
		g_client.process();
	if (g_client.is_connected)
		error("SERVER is not active anymore", "CLIENT");
	return (0);
}

void	get_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		if (!g_client.is_connected)
		{
			ft_printf("CLIENT: SERVER cannot connect for a while\n");
			sleep(2);
		}
		else
		{
			ft_printf("CLIENT: Message sent successfully.\n");
			g_client.is_connected = 0;
		}
	}
	else
		g_client.is_connected = 1;
}
