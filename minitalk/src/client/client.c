/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:47:14 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 19:37:41 by vlima-nu         ###   ########.fr       */
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
	while (g_client.is_connected > 0)
		g_client.process();
	if (g_client.is_connected == -1)
		error("Connection refused by SERVER,\nCould not send message.", \
			"CLIENT");
	else if (!errno)
		ft_printf("CLIENT: Message sent successfully.\n");
}

void	get_signal(int signal)
{
	if (signal == SIGUSR1)
		g_client.is_connected = -1;
}
