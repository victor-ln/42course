/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:40:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 21:02:42 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "minitalk.h"

/*
	Saves the server pid, sets function pointer to send message length,
	copies the string to be passed and sets connection and signals.
*/
void		start_struct(char **args);

/*
	Checks if the pid format is valid, if the process exists and
	if you have permission to send the message. Return pid if no error occurs.
*/
pid_t		check_pid(char *ptr);

/*
	Keeps connection with server till string is sent or some error occurs.
*/
void		start_connection(void);

/*
	Checks if server still handling the message.
*/
void		get_signal(int signal);

/*
	Sends the length of the string in 32 bits, then changes process pointer to
	send the message.
*/
void		send_message_len(void);

/*
	Sends the message, each bit of each byte then sets connection off.
*/
void		send_message(void);

#endif
