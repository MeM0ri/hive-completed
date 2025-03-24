/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:36 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/23 20:38:21 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_confirm_recived = 0;

void	send_length(int pid, long length)
{
	int	i;

	ft_printf("Sending length.\n");
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

void	send_bit(int pid, char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_confirm_recived)
			pause();
		usleep(50);
		g_confirm_recived = 0;
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
	long				i;

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
	send_length(server_pid, ft_strlen(argv[2]));
	i = -1;
	while (argv[2][++i] != '\0')
		send_bit(server_pid, argv[2][i]);
	exit(EXIT_SUCCESS);
}
