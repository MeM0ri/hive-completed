/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfokin <alfokin@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:56:16 by alfokin           #+#    #+#             */
/*   Updated: 2025/03/19 15:51:54 by alfokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	get_string(int *bit, char **string, long *length, int signum)
{
	static long	index;
	static char	byte;

	if (signum == SIGUSR1)
		byte |= (0 << *bit);
	else if (signum == SIGUSR2)
		byte |= (1 << *bit);
	if (*bit == 8)
	{
		(*string)[index++] = byte;
		(*length)--;
		*bit = 0;
		byte = 0;
	}
	(*bit)++;
}

void	get_length(int *bit, long *length, int signum)
{
	if (signum == SIGUSR1)
		*length |= (0 << *bit);
	else if (signum == SIGUSR2)
		*length |= (1 << *bit);
	(*bit)++;
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	*string;
	static long	length;
	static bool	is_length;

	(void)context;
	if (bit < 32 && !is_length)
		get_length(&bit, &length, signum);
	else if (bit == 32 && !is_length)
	{
		is_length = true;
		string = malloc(sizeof(char) * (length + 1));
		if (!string)
			ft_printf("[ERROR] String allocation failure.");
		bit = 0;
		ft_printf("Length got: %i\n", (int)length);
	}
	else if (length > 0 && is_length)
	{
		get_string(&bit, &string, &length, signum);
		printf("Getting string: %s\n", string);
	}
	else if (length == 0 && is_length)
	{
		string[ft_strlen(string)] = '\0';
		printf("%s\n", string);
		//free(string);
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
