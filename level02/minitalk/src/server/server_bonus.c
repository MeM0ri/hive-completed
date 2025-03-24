/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:16 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/24 17:07:55 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

volatile t_server	g_server = {0, false, NULL, 0, 0, 0};

static void	handle_length(int signum, siginfo_t *info)
{
	if (signum == SIGUSR2)
		g_server.length |= (1UL << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 32)
	{
		g_server.is_length = true;
		if (g_server.length > 0)
			g_server.string = malloc(sizeof(char) * (g_server.length + 1));
		if (!g_server.string)
		{
			g_server.is_length = false;
			g_server.bit = 0;
			g_server.length = 0;
			g_server.index = 0;
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		g_server.bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

static void	handle_message(int signum, siginfo_t *info)
{
	if (signum == SIGUSR2)
		g_server.byte |= (1 << g_server.bit);
	g_server.bit++;
	if (g_server.bit == 8)
	{
		g_server.string[g_server.index++] = g_server.byte;
		g_server.length--;
		if (g_server.length == 0)
		{
			g_server.string[g_server.index] = '\0';
			ft_printf("%s\n", g_server.string);
			free(g_server.string);
			g_server.string = NULL;
			g_server.is_length = false;
			g_server.index = 0;
			g_server.bit = 0;
			g_server.byte = 0;
			kill(info->si_pid, SIGUSR1);
			return ;
		}
		g_server.bit = 0;
		g_server.byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (!g_server.is_length)
		handle_length(signum, info);
	else
		handle_message(signum, info);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	ft_printf("Server PID: %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
