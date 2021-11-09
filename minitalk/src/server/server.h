/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:16:09 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 19:51:27 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../../inc/minitalk.h"

# define DIFF_PID "SERVER: Handling signals from another client now\n"

void		handler(int signal, siginfo_t *info, void *null);
void		get_message_len(int signal, t_server *server);
void		get_message(int signal, t_server *server);
void		restart_server(t_server *server);

#endif
