/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:01:52 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 19:46:15 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <sys/types.h>
# include <signal.h>
# include <errno.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct sigaction	t_sigaction;

typedef struct s_client
{
	char		*message;
	size_t		message_len;
	pid_t		server_pid;
	void		(*process)(void);
	int			signals[2];
	int			is_connected;
}	t_client;

typedef struct s_server
{
	char		*message;
	size_t		message_len;
	int			message_sent;
	pid_t		client_pid;
	void		(*process)(int, struct s_server *);
}	t_server;

void		error(char *message, char *who);

#endif
