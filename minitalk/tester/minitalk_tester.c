/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:23:10 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/06 11:05:39 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

typedef struct s_minitalk_tester
{
	char	*command;
	int		test;
	int		fork_pid;
	char	server_pid[10];
	int		server_pid_n;
}	t_minitalk_tester;

void	rand_text(char *command, char *pid);

int	main(void)
{
	t_minitalk_tester	root;

	root.command = malloc(400);
	root.fork_pid = fork();
	if (root.fork_pid)
		system("../server");
	else
	{
		usleep(500000);
		printf("\nType your server PID : ");
		scanf("%s", root.server_pid);
		root.test = 0;
		while (++root.test <= 100)
		{
			printf("\n\n/*			TEST : %d			*/\n\n", root.test);
			rand_text(root.command, root.server_pid);
			system(root.command);
		}
		printf("\n\nAll tests done\n\n");
		free(root.command);
		root.server_pid_n = atoi(root.server_pid);
		if (!kill(root.server_pid_n, 0))
			kill(root.server_pid_n, SIGINT);
	}
	return (0);
}

void	rand_text(char *command, char *pid)
{
	char	*str;
	int		index;
	int		before;

	str = "01234568789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVVWXYZ";
	memset(command, 0, 400);
	strcpy(command, "../client ");
	strcat(command, pid);
	index = strlen(command);
	before = index + 1;
	command[index] = ' ';
	while (++index < 400)
		command[index] = str[rand() % 65];
	printf("Expected : \n%s\n", command + before);
	printf("\nGot : \n");
}
