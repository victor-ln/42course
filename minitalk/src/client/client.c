/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:47:14 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/10 15:14:26 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_client	g_client;

#define INV_ARGC "Invalid number of arguments\n\
it needs the server PID and the message to send"

int	main(int argc, char **argv)
{
	if (argc != 3)
		error(INV_ARGC, "CLIENT");
	start_struct(argv);
	start_connection();
	return (0);
}

void	start_connection(void)
{
	t_sigaction	sa;

	ft_bzero(&sa, sizeof(t_sigaction));
	sa.sa_handler = get_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	connect();
	while (!kill(g_client.server_pid, 0) && g_client.is_connected)
		g_client.process();
	if (!g_client.is_connected)
		ft_printf("CLIENT: Message sent successfully.\n");
}

void	get_signal(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("CLIENT: SERVER cannot connect for a while\n");
		sleep(1);
	}
	else
		g_client.is_connected = 1;
}
