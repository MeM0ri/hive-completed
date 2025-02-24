/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:16 by alfokin           #+#    #+#             */
/*   Updated: 2025/02/24 17:01:20 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	byte;

	(void)context;
	if (signum == SIGUSR1)
		byte |= (0 << bit);
	else if (signum == SIGUSR2)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", byte);
		bit = 0;
		byte = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("Server PID: %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	exit(EXIT_SUCCESS);
}
