/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:15:05 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 19:51:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	main(void)
{
	t_sigaction		sa;

	ft_bzero(&sa, sizeof(t_sigaction));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	ft_printf("SERVER: PID is %d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

void	handler(int signal, siginfo_t *info, void *null)
{
	static t_server	server;

	if (server.client_pid != info->si_pid)
	{
		if (server.client_pid)
		{
			kill(server.client_pid, SIGUSR1);
			ft_printf(DIFF_PID);
			if (!server.message_sent)
				restart_server(&server);
			server.message_sent = 0;
		}
		else
		{
			ft_bzero(&server, sizeof(t_server));
			server.process = get_message_len;
		}
		server.client_pid = info->si_pid;
	}
	server.process(signal, &server);
	kill(info->si_pid, SIGUSR2);
	(void)null;
}

void	get_message_len(int signal, t_server *server)
{
	static int	bits;

	server->message_len <<= 1;
	if (signal == SIGUSR2)
		server->message_len++;
	if (++bits == 32)
	{
		bits = 0;
		server->process = get_message;
		server->message = (char *)malloc(server->message_len + 1);
		if (!server->message)
		{
			kill(server->client_pid, SIGUSR1);
			error("Malloc for client message failed", "SERVER");
		}
	}
}

void	get_message(int signal, t_server *server)
{
	static size_t	byte;
	static int		bit;
	static char		ch;

	ch <<= 1;
	if (signal == SIGUSR2)
		ch++;
	if (++bit == 8)
	{
		server->message[byte++] = ch;
		if (byte == server->message_len)
		{
			server->message[byte] = 0;
			ft_printf("SERVER: Message from %d:\n%s\n", \
				server->client_pid, server->message);
			restart_server(server);
			server->message_sent = 1;
			byte = 0;
		}
		bit = 0;
		ch = 0;
	}
}

void	restart_server(t_server *server)
{
	if (server->message)
		free(server->message);
	server->message_len = 0;
	server->message = 0;
	server->process = get_message_len;
}
