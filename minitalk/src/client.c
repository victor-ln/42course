/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:47:14 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/06 11:08:19 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_message(__pid_t pid, char *message);
static int	check_pid(char *ptr, __pid_t *pid);
static void	error(char *message);

int	main(int argc, char **argv)
{
	__pid_t		pid;

	pid = 0;
	if (argc != 3)
		error("Invalid number of arguments");
	else if (!check_pid(argv[1], &pid))
		error("Invalid Process Identifier");
	else if (kill(pid, 0))
	{
		if (errno == EPERM)
			error("You don't have permission to send a signal");
		else if (errno == ESRCH)
			error("Process does not exist");
	}
	else
		send_message(pid, argv[2]);
	return (0);
}

static int	check_pid(char *ptr, __pid_t *pid)
{
	while (ft_isdigit(*ptr))
	{
		*pid = *pid * 10 + *ptr - '0';
		ptr++;
	}
	if (!*ptr)
		return (1);
	return (0);
}

static void	send_message(__pid_t pid, char *message)
{
	int		ch;
	int		bits;

	while (*message)
	{
		bits = 0;
		ch = *message;
		while (bits < 7)
		{
			if (ch % 2)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(250);
			ch /= 2;
			bits++;
		}
		message++;
	}
}

static void	error(char *message)
{
	write(2, "Error\n", 6);
	while (*message)
		write(2, message++, 1);
	write(2, "\n", 1);
	exit(1);
}
