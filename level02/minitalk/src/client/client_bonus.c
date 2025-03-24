/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:36 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/24 17:45:37 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_confirm_recived = 0;

void	send_length(int pid, long length)
{
	int	i;

	i = -1;
	while (++i < 32)
	{
		if ((length >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_confirm_recived)
			pause();
		g_confirm_recived = 0;
	}
}

void	send_string(int pid, char *string)
{
	int	i;

	while (*string)
	{
		i = -1;
		while (++i < 8)
		{
			if ((*string >> i) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_confirm_recived)
				pause();
			g_confirm_recived = 0;
		}
		string++;
	}
}

void	confirm_signal(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	g_confirm_recived = 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	sa.sa_sigaction = confirm_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) != 0)
	{
		ft_printf("[ERROR] Wrong server pid.\n");
		exit(EXIT_FAILURE);
	}
	send_length(server_pid, ft_strlen(argv[2]));
	send_string(server_pid, argv[2]);
	exit(EXIT_SUCCESS);
}
