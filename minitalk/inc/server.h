/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:16:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 21:08:46 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "minitalk.h"

# define DIFF_PID "SERVER: Handling signals from another client now\n"

/*
	Receives the signal SIGUSR1 or SIGUSR2 and some info about the sender.
	Checks if the signal is the same received from the last client and handles it.
*/
void		handler(int signal, siginfo_t *info, void *null);

/*
	Calculates the length of the string being received and allocates memory for it.
*/
void		get_message_len(int signal, t_server *server);

/*
	Calculates each bit received until completes a byte, and stores its value in the
	string to be displayed when the number of bytes is equal to the message length.
*/
void		get_message(int signal, t_server *server);

/*
	Frees allocated memory and set to zero most variables.
*/
void		restart_server(t_server *server);

#endif
