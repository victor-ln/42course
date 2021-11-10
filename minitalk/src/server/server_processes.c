/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 07:44:40 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/10 15:08:59 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
			error("Malloc for message string failed", "SERVER");
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
			ft_printf("SERVER: Message:\n%s\n", server->message);
			start_server(server);
			byte = 0;
		}
		bit = 0;
		ch = 0;
	}
}

void	start_server(t_server *server)
{
	if (server->message)
		free(server->message);
	server->process = get_message_len;
	server->message_len = 0;
	server->message = 0;
}
