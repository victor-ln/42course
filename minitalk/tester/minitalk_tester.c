/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlima-nu <vlima-nu@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:23:10 by vlima-nu          #+#    #+#             */
/*   Updated: 2021/11/09 20:26:57 by vlima-nu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <signal.h>

typedef struct s_tester
{
	char	*command;
	int		test;
	int		fork_pid;
	char	server_pid[10];
	int		server_pid_n;
	size_t	characters_sent;
}	t_tester;

void	rand_text(t_tester *root);

int	main(void)
{
	t_tester	root;

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
		root.characters_sent = 0;
		while (++root.test <= 100)
		{
			printf("\n\n/*			TEST : %d			*/\n\n", root.test);
			rand_text(&root);
			system(root.command);
		}
		printf("\n\nAll tests done\n\n");
		free(root.command);
		root.server_pid_n = atoi(root.server_pid);
		if (!kill(root.server_pid_n, 0))
			kill(root.server_pid_n, SIGINT);
		printf("Characters sent: %ld\n", root.characters_sent);
	}
	return (0);
}

void	rand_text(t_tester *root)
{
	char	*str;
	int		index;
	int		before;

	str = "01234568789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVVWXYZ";
	memset(root->command, 0, 400);
	strcpy(root->command, "../client ");
	strcat(root->command, root->server_pid);
	index = strlen(root->command);
	before = index + 1;
	root->command[index] = ' ';
	while (++index < 400)
		root->command[index] = str[rand() % 65];
	printf("Expected : \n%s\n", root->command + before);
	root->characters_sent += strlen(root->command + before);
	printf("\nGot : \n");
}
