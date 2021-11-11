/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:15:05 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/11 05:40:26 by vlima-nu         ###   ########.fr       */
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
		if (server.message && server.client_pid)
		{
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		server.client_pid = info->si_pid;
		server.process = confirm_signal;
	}
	server.process(signal, &server);
	(void)null;
}
