/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:16:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/13 13:12:23 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "minitalk.h"

/*
	Receives the signal SIGUSR1 or SIGUSR2 and some info about the sender.
	Checks if the signal is the same received from the current process. If it is,
	keeps process running, else sends a signal for the new client wait a while.
*/
void		handler(int signal, siginfo_t *info, void *null);

/*
	Calculates the length of the string being received and allocates memory for it.
*/
void		get_message_len(int signal, t_server *server);

/*
	Calculates every bit received until it completes a byte,
	and stores its value in the string to be displayed when
	the number of bytes is equal to the message length.
*/
void		get_message(int signal, t_server *server);

/*
	Confirms the start or end of the connection and sets the
	function pointer to get_message_len() and message_len to zero.
*/
void		confirm_signal(int signal, t_server *server);

#endif
