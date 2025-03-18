/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:36 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/18 15:40:37 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

volatile sig_atomic_t	g_confirm_recived = 0;

void	send_bit(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		while (!g_confirm_recived)
			pause();
		g_confirm_recived = 0;
		i++;
	}
}

void	confirm_signal(int signum)
{
	(void)signum;
	g_confirm_recived = 1;
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int		i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server_pid> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	signal(SIGUSR1, confirm_signal);
	i = -1;
	while (argv[2][++i] != '\0')
		send_bit(server_pid, argv[2][i]);
	send_bit(server_pid, '\n');
	exit(EXIT_SUCCESS);
}
