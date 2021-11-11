/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 07:13:31 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/11 05:38:33 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

extern t_client	g_client;

pid_t	check_pid(char *ptr)
{
	pid_t	pid;

	pid = 0;
	while (ft_isdigit(*ptr))
	{
		pid = pid * 10 + *ptr - '0';
		ptr++;
	}
	if (*ptr)
		error("Invalid Process Identifier", "CLIENT");
	else if (kill(pid, 0))
	{
		if (errno == EPERM)
			error("You don't have permission to send a signal to this PID", \
				"CLIENT");
		else if (errno == ESRCH)
			error("Process does not exist", "CLIENT");
	}
	return (pid);
}

void	start_struct(char **args)
{
	g_client.server_pid = check_pid(args[1]);
	g_client.process = send_message_len;
	g_client.message = args[2];
	g_client.message_len = ft_strlen(args[2]);
	g_client.signals[0] = SIGUSR1;
	g_client.signals[1] = SIGUSR2;
	g_client.is_connected = 0;
	if (!g_client.message_len)
		error("Empty message", "CLIENT");
}

void	send_message_len(void)
{
	static int		i = 32;

	if (i)
	{
		kill(g_client.server_pid, \
			g_client.signals[(g_client.message_len >> (--i)) & 1]);
		usleep(10000);
	}
	else
		g_client.process = send_message;
}

void	send_message(void)
{
	static int		bit = 8;
	static int		byte;

	if (bit)
	{
		kill(g_client.server_pid, \
			g_client.signals[(g_client.message[byte] >> (--bit)) & 1]);
		usleep(10000);
	}
	else if (g_client.message[++byte])
		bit = 8;
	else
	{
		kill(g_client.server_pid, SIGUSR2);
		usleep(10000);
	}
}

void	connect(void)
{
	while (!g_client.is_connected)
	{
		if (kill(g_client.server_pid, SIGUSR1))
			error("SERVER is not active anymore", "CLIENT");
		usleep(10000);
	}
	ft_printf("CLIENT: Connection established\n");
}
