/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 17:40:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 19:22:15 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../../inc/minitalk.h"

void		start_struct(char **args);
pid_t		check_pid(char *ptr);
void		start_connection(void);
void		get_signal(int signal);
void		send_message_len(void);
void		send_message(void);

#endif
