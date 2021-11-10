/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:40:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/10 15:29:31 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "minitalk.h"

/*
	Saves the server pid, sets function pointer to send message length,
	copies the string to be passed and sets the signals.
*/
void		start_struct(char **args);

/*
	Checks if the pid format is valid, if the process exists and
	if you have permission to send the message. Returns pid if no error occurs.
*/
pid_t		check_pid(char *ptr);

/*
	Keeps connection with server till string is sent or some error occurs.
*/
void		start_connection(void);

/*
	Checks if server can handle the message.
*/
void		get_signal(int signal);

/*
	Sends the length of the string in 32 bits, then changes process pointer to
	send the message.
*/
void		send_message_len(void);

/*
	Sends the message, every bit of every byte then disconnects the connection.
*/
void		send_message(void);

/*
	Sends signals to the server each 2 seconds till server be able to connect.
*/
void		connect(void);

#endif
